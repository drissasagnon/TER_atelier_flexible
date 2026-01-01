
/*###########################################################################
## ___ __ __                      __                      ___              ##
##  | |_ |__)   /\ |_ _ |o _  _  |_ | _   o|_ | _    __    |    |_ _       ##
##  | |__| \   /--\|_(-`||(-`|   |  |(-`><||_)|(-`         | |_||_(_)      ##
##                                                                         ##
############################################################################*/
 
/*!
 * \file Tuto_Basique.main_commande.cpp
 * \brief code correspondant au tuto du sujet de TER atelier flexible
 * \author Team Tuto_Basique (N7 2023-2024)
 * \version 0.1
*/

#include "capteurs.h"
#include "actionneurs.h"
#include "commande.h"
#include "RobotsInterface.h"
#include "AigsInterface.h"
#include <ros/ros.h>
#include <unistd.h>

using namespace std;

#include "prodconfig/productconfig.h"

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#define PlaceFin 1000 /* Marquage à ne pas dépasser */

int M[PlaceFin+1];

/* *****************************************************************
///////////  | Exemple configuration produits : début |  //////////
 ******************************************************************* */

// type de produit : séquence de POSTES : durée par poste : nombre de produits
// 2 : 1 4 : 4 5 : 2
// 6 : 7 6 5 : 3 6 3 : 1

/*
const vector<int> Prod_type{    2,
                                6};

const vector<int> Prod_qte{ 2,
                            1};

const vector<vector<int>> Prod_seqdeposte{  { POSTE_1, POSTE_4 },
                                            { POSTE_7, POSTE_6, POSTE_5 }};

const vector<vector<int>> Prod_dureeparposte{   { 4, 5 },
                                                { 3, 6, 3 }};
*/
/* ********************************************************
///////////  | Exemple configuration produits : fin |  //////////
 ******************************************************** */



/////////////////////////////////////////////////////////////////////////
//////////////////// | DEBUT DECLARE ETU | /////////////////
/////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
/////////////////////  |  FIN DECLARE ETU  |   /////////////////
/////////////////////////////////////////////////////////////////////////


// Pour l'affichage //
void display()
{
    cout << endl;
    for (int i=0;i<=PlaceFin;i++)
    {
        if(i==0)
            cout << "Marquage : ";

        if(M[i]>0)
            cout<<BOLDRED<<"M["<<i<<"]="<<M[i]<<RESET<<", ";
        if(M[i]<0)
            cout<<BOLDGREEN<<"M["<<i<<"]="<<M[i]<<RESET<<", ";
    }
    cout<<endl<<endl;
}

void ShutdownCallback(const std_msgs::Byte::ConstPtr& msg)
{
        ros::shutdown();
}

int main(int argc, char **argv)
{
    /* *************************************************
    ///////////  | Debut du Petri plus bas |  //////////
     ************************************************* */


    ros::init(argc, argv, "commande");
    ros::NodeHandle noeud;

    ros::Publisher pub_spawnShuttles = noeud.advertise<std_msgs::Int32>("/commande_locale/nbNavettes",10);
    ros::Subscriber sub_shutdown = noeud.subscribe("/commande_locale/shutdown",10,&ShutdownCallback);

    int nbRobot=atoi(argv[1]);

    Commande cmd(noeud,argv[0]);
    RobotsInterface robot(noeud,nbRobot);
    AigsInterface aiguillage(noeud);
    Capteurs capteur(noeud);

    ros::Rate loop_rate(25); //fréquence de la boucle

    // On attend la fin de l'initialisation des robots
    while(!robot.RobotInitialise(1) || !robot.RobotInitialise(2))
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
    while(nbRobot==4 && (!robot.RobotInitialise(3) || !robot.RobotInitialise(4)))
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

    /* *************************************************
    // | Creation des Navettes | //
     ************************************************* */
    
    int nbNavettes=0;//Mettre 0 pour demander a l'utilisateur
    while(nbNavettes<1||nbNavettes>6)
    {
        cout << "Combien voulez vous de navettes ? [1..6]" << endl;
        cin >> nbNavettes;
        if(cin.fail())
        {
            cout << endl << " [Erreur mauvais choix ..]" << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
    }
    
    std_msgs::Int32 msg_nbNavettes;
    msg_nbNavettes.data=nbNavettes;
    pub_spawnShuttles.publish(msg_nbNavettes);
    

    cmd.Initialisation();
    for(int i=0;i<PlaceFin;i++) M[i]=0;

    /* *************************************************
    ////// | MARQUAGE INITIAL | ////////
    ************************************************* */
    M[0]=1;
    display();

    ///////////////////////////////////////////////////////////////////
    ///////////////////// | DEBUT INIT ETU | ///////////////////
    ///////////////////////////////////////////////////////////////////
    int nb_type_prod = Prod_type.size();
	int index_prod = 0; // initialisation pour pointer sur le premier produit de la liste des types de produits
	int index1_prod = 0;
	int index2_prod = 0;
	int index_prod_post3 = 0;
	int index_prod_post4 = 0;
	int index_prod_shuttle = 0;
	int index1_seq = 0; // initialisation pour pointer sur la premiÃ¨re sequence de la gamme du produit 1
	int index2_seq = 0; // initialisation pour pointer sur la premiÃ¨re sequence de la gamme du produit 2
	int index_seq_post3 = 0;
	int index_seq_post4 = 0;
	int index_seq_shuttle = 0;
	M[205] = nb_type_prod;
	M[214] = 1;
	M[224] = 1;
	M[250] = 1;
	M[3] = 1; // initialisation avec le poste 3 libre
	M[4] = 1; // initialisation avec le poste 4 libre
	M[262] = 1; // initialisation de compteur

	int qte_totale = 0; 
	int qte_produite = 0;
	for(int i=0; i< nb_type_prod; i++){
		qte_totale = qte_totale + Prod_qte[i];
	}
	cout<<"qte a produire = "<<qte_totale<<endl;
    ///////////////////////////////////////////////////////////////////
    /////////////////////  |  FIN INIT ETU  |  ////////////////////
    ///////////////////////////////////////////////////////////////////
	bool debut_bug = false;
    while (ros::ok())
    {
        // Seulement si la simulation est en cours
		if(cmd.getPlay()==true)
		{
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //////////////////////////////////////// | DEBUT PETRI  ETU | /////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(M[0])
            {
				/*!
				* \b T1:  init aiguillages et produit
				* \arg  positionnement des aiguillages 
				* \arg \b Precondition: M[0] && M[PlaceAmontBis] && CONDITIONS_debut
				* \arg \b Postcondition: M[101]++; M[201]=2;
				*/
				M[0]--;
				//ACTIONâ€¦.
				aiguillage.Gauche(1);
				aiguillage.Droite(2);
				aiguillage.Gauche(3);
				aiguillage.Gauche(10);
				aiguillage.Gauche(11);
				aiguillage.Gauche(12);
				//cmd.Stop_PS(2);
				M[101]++;
				M[201]=2;
				display();
            }

			if(M[101] && capteur.get_PS(6)){
				/*!
				* \b T2:  aiguillage A02 mis en place
				* \arg  positionnement de aiguillage 2 Ã  gauche pour laisser sortie la navette de la zone de travail 
				* \arg \b Precondition: M[101] && capteur.get_PS(6)
				* \arg \b Postcondition: 
				*/

				M[101]--;
				if (!M[101])
				{
					cout<<"M[101] has no token any more :) \n";
				}else{ cout<<"M[101] still has a token :( \n";}
				aiguillage.Gauche(2);
				display();
			}

		// -----------------------------------------------------------------------
		// Section production 
		// -----------------------------------------------------------------------

			if(M[205] && M[224] && (M[203]==0)){
				/*!
				* \b T205:  Lancement d'un nouveau type produit
				* \arg  VÃ©rifie si la fabrication d'un type de produit est terminer pour pouvoir lancer le prochain
				* \arg \b Precondition: M[205] && (M[203]==0)
				* \arg \b Postcondition: M[204]=index_prod + 1;
				*/
				M[205]--;
				M[224]--;
				index_prod++;
				M[204]=index_prod;
				display();
			}

			if(M[204]>0 && Prod_qte[M[204]-1]>1 && M[262] && M[3] && Prod_seqdeposte[M[204]-1][0]==POSTE_3){
				/*!
				* \b T204:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[204]>0 && Prod_qte[M[204]-1]>1 && M[3] && Prod_seqdeposte[M[204]-1][0]==POSTE_3
				* \arg \b Postcondition: M[203]=Prod_qte(M[204]-1); M[206]++; M[240]++; M[3]++;
				*/
				index1_prod = index_prod;
				index2_prod = index1_prod;
				M[203]=Prod_qte[M[204]-1];
				M[260]=Prod_qte[M[204]-1];
				M[3]--;
				M[262]--;
				M[206] = 2;
				M[240] = 2;
				M[204]=0;
				M[3]++;
				display();
			}

			if(M[204]>0 && Prod_qte[M[204]-1]>1 && M[262] && M[4] && Prod_seqdeposte[M[204]-1][0]==POSTE_4){
				/*!
				* \b T204:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[204]>0 && Prod_qte[M[204]-1]>1 && M[3] && Prod_seqdeposte[M[204]-1][0]==POSTE_3
				* \arg \b Postcondition: M[203]=Prod_qte(M[204]-1); M[206]++; M[240]++; M[3]++;
				*/
				index1_prod = index_prod;
				index2_prod = index1_prod;
				M[203]=Prod_qte[M[204]-1];
				M[260]=Prod_qte[M[204]-1];
				M[4]--;
				M[262]--;
				M[206] = 2;
				M[240] = 2;
				M[204]=0;
				M[4]++;
				display();
			}

			if(M[204]>0 && Prod_qte[M[204]-1]<=1){
				/*!
				* \b T204:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[204]>0 && Prod_qte[M[204]-1]<=1
				* \arg \b Postcondition: M[245]++; M[247]++;
				*/
				M[203]=Prod_qte[M[204]-1];
				M[245]++; 
				M[247]++;
				M[204]=0;
				display();
			}

			if(M[245] && M[3] && Prod_seqdeposte[M[204]-1][0]==POSTE_3){
				/*!
				* \b T245:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[245]
				* \arg \b Postcondition: M[206]=2; M[246]=1;
				*/
				M[245]--;
				M[206] = 2;
				M[246]=1;
				index1_prod = index_prod;
				display();
			}

			if(M[245] && M[4] && Prod_seqdeposte[M[204]-1][0]==POSTE_4){
				/*!
				* \b T245:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[245]
				* \arg \b Postcondition: M[206]=2; M[246]=1;
				*/
				M[245]--;
				M[206] = 2;
				M[246]=1;
				index1_prod = index_prod;
				display();
			}

			if(M[247] && M[205]>=1 && M[250]){
				/*!
				* \b T247:  Lancement d'un nouveau type de produit
				* \arg  VÃ©rifie si la fabrication d'un type de produit est terminer pour pouvoir lancer le prochain
				* \arg \b Precondition: M[247] && M[205]>=1 && M[250]
				* \arg \b Postcondition: M[248]=index_prod; 
				*/
				index_prod++;
				index2_prod = index_prod;
				M[247]--;
				M[250]--;
				M[205]--;
				M[248]=index2_prod;
				display();
			}

			if(M[248] && M[3] && Prod_seqdeposte[M[248]-1][0]==POSTE_3){
				/*!
				* \b T204:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[248]
				* \arg \b Postcondition: M[240] = 2; M[249]=Prod_qte[M[248]-1];
				*/

				M[248]--;
				M[240] = 2;
				M[249]=Prod_qte[M[248]-1];
				display();
			}

			if(M[248] && M[4] && Prod_seqdeposte[M[248]-1][0]==POSTE_4){
				/*!
				* \b T204:  mise Ã  jour de la quantitÃ© Ã  produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantitÃ©
				* \arg \b Precondition: M[248]
				* \arg \b Postcondition: M[240] = 2; M[249]=Prod_qte[M[248]-1];
				*/

				M[248]--;
				M[240] = 2;
				M[249]=Prod_qte[M[248]-1];
				display();
			}

			if(M[201] && M[203]>0){
				/*!
				* \b T201_203:  lancement de la production d'une unitÃ© d'un type de produit.
				* \arg  AprÃ¨s vÃ©rification que la quantitÃ© Ã  produire n'est pas atteinte
				* \arg \b Precondition: M[201] && M[203]
				* \arg \b Postcondition: M[207]++;
				*/

				M[201]--;
				M[203]--;
				M[207]++;
				display();
			}

			if(M[201] && M[246]>0){
				/*!
				* \b T201_246:  lancement de la production d'une unitÃ© d'un type de produit. 
				* \arg  AprÃ¨s vÃ©rification que la quantitÃ© Ã  produire n'est pas atteinte. Dans le cas où la quantité à produire est égale à 1
				* \arg \b Precondition: M[201] && M[246]>0
				* \arg \b Postcondition: M[207]++;
				*/

				M[201]--;
				M[246]--;
				M[207]++;
				display();
			}

			if(M[201] && M[249]>0){
				/*!
				* \b T201_246:  lancement de la production d'une unitÃ© d'un deuxième type de produit. 
				* \arg  AprÃ¨s vÃ©rification que la quantitÃ© Ã  produire n'est pas atteinte. Dans le cas où la quantité à produire pour le premier type de produit est 1
				* \arg \b Precondition: M[201] && M[249]>0
				* \arg \b Postcondition: M[207]++;
				*/

				M[201]--;
				M[249]--;
				M[207]++;
				display();
			}
			if(M[242]==0 && M[249]==0 && M[250]==0){
				/*!
				* \b T249_bis:  Autoriser le lancement d'un nouveau produit quand la quantité à produire pour le deuxième type de produit est atteinte
				* \arg  : 
				* \arg \b Precondition: M[242]==0 && M[249]==0 && M[250]==0
				* \arg \b Postcondition: M[250]++;
				*/
				M[250]++;
				display();
			}

			if(M[206]>0 && M[208]==0){
				/*!
				* \b T4:  Initialisation du nombre de séquence dans la gamme du produit indexé 1
				* \arg  VÃ©rifie si le produit est fabriquer pour pouvoir lancer le prochain en initialisant le nouveau nombre de sÃ©quence
				* \arg \b Precondition: M[206] && M[208]==0
				* \arg \b Postcondition: M[208]=Prod_seqdeposte[index1_prod-1].size();
				*/
				M[206]--;
				M[208] = Prod_seqdeposte[index1_prod-1].size();
				display();
			}

			if(M[208]>0 && M[206]){
				/*!
				* \b T208:  initialisation de pour pointer sur la premiÃ¨re sequence d'une gamme
				* \arg  
				* \arg \b Precondition: M[208]>0 && M[206]
				* \arg \b Postcondition: M[209]++;
				*/
				M[208]--;
				M[206]--;
				index1_seq = 0;
				M[209]++;
				display();
			}


			if(M[240]>0 && M[241]==0){
				/*!
				* \b T240:  Initialisation du nombre de sÃ©quence dans une gamme
				* \arg  VÃ©rifie si le produit est fabriquer pour pouvoir lancer le prochain en initialisant le nouveau nombre de sÃ©quence
				* \arg \b Precondition: M[240]>0 && M[241]==0
				* \arg \b Postcondition: M[241]=Prod_seqdeposte[index2_prod-1].size();
				*/
				M[240]--;
				M[241] = Prod_seqdeposte[index2_prod-1].size();
				display();
			}

			if(M[241]>0 && M[240]){
				/*!
				* \b T241:  initialisation de pour pointer sur la premiÃ¨re sequence d'une gamme
				* \arg  
				* \arg \b Precondition: M[241]>0 && M[240]
				* \arg \b Postcondition: M[209]++;
				*/
				M[241]--;
				M[240]--;
				index2_seq = 0;
				M[242]++;
				display();
			}
			// ---- Poste 3 ------------------------------------------------
			if(M[207] && M[209] && M[3] && Prod_seqdeposte[index1_prod-1][index1_seq] == POSTE_3){
				/*!
				* \b T207_209_3_1:  Ajout d'un produit indexé 1 au poste 3 
				* \arg  VÃ©rifie si le poste de dÃ©part de la gamme d'un produit est le poste 3 et si le poste 3 est libre
				* \arg \b Precondition: M[207] && M[209] && M[3] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_3 , M[209]
				* \arg \b Postcondition: M[210]++; M[251]++;
				*/	
				M[207]--;
				M[209]--;
				M[3]--;
				index_prod_post3 = index1_prod;
				index_seq_post3 = index1_seq;
				robot.AjouterProduit(Prod_seqdeposte[index_prod_post3-1][index_seq_post3], Prod_type[index_prod_post3-1]);
                M[210]++;
				M[251]++;
				display();
			}


			if(M[207] && M[242] && M[3] && Prod_seqdeposte[index2_prod-1][index2_seq] == POSTE_3){
				/*!
				* \b T207_240_3_2:  Ajout d'un produit indexé 2 au poste 3 
				* \arg  VÃ©rifie si le poste de dÃ©part de la gamme d'un produit est le poste 3 et si le poste 3 est libre
				* \arg \b Precondition: M[207] && M[242] && M[3] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_3 , M[209]
				* \arg \b Postcondition: M[210]++; M[252]++;
				*/
				M[207]--;
				M[242]--;
				M[3]--;
				index_prod_post3 = index2_prod;
				index_seq_post3 = index2_seq;
				robot.AjouterProduit(Prod_seqdeposte[index_prod_post3-1][index_seq_post3], Prod_type[index_prod_post3-1]);
                M[210]++;
				M[252]++;
				display();
			}

			if(M[210]){
				/*!
				* \b T210:  fabrication d'un produit au poste 3
				* \arg  fabrication en cours au poste 3
				* \arg \b Precondition: M[210]
				* \arg \b Postcondition: M[211]++;
				*/
				M[210]--;
				robot.FaireTache(Prod_seqdeposte[index_prod_post3-1][index_seq_post3], Prod_dureeparposte[index_prod_post3-1][index_seq_post3]);
                cout << "duree poste=" << Prod_dureeparposte[index_prod_post3-1][index_seq_post3] << endl;
				M[211]++;
				display();
			}

			if(M[211] && robot.TacheFinie(POSTE_3)){
				/*!
				* \b T211:  vÃ©rifier si est finie au poste 3
				* \arg  fin fabrication du produit au poste 3
				* \arg \b Precondition: M[211] && robot.TacheFinie(POSTE_3)
				* \arg \b Postcondition: M[212]++;
				*/
				M[211]--;
				M[212]++;
				display();
			}

			if(M[212] && M[208]==0 && M[251]){
				/*!
				* \b T212_208barre_251:  Evacuation du produit au poste 3
				* \arg  fin de fabrication au poste 3 et Ã©vacuation
				* \arg \b Precondition: M[212] && M[208]==0 && M[251]
				* \arg \b Postcondition: M[201]++; M[206] = 2; M[222]++; M[223]++; M[3]++;
				*/
				M[212]--;
				M[251]--;
				robot.Evacuer();
				qte_produite++;
				cout<<"qte produite = "<<qte_produite<<endl;
				cout<<"qte a produire = "<<qte_totale<<endl;
				M[201]++;
				M[206]=2;
                M[222]++;
                M[223]++;
				M[3]++;
				M[261]++;
				display();
			}  

			if(M[212] && M[241]==0 && M[252]){
				/*!
				* \b T212_241barre_252:  Evacuation du produit au poste 3
				* \arg  fin de fabrication au poste 3 et Ã©vacuation
				* \arg \b Precondition: M[212] && M[241]==0 && M[252]
				* \arg \b Postcondition: M[201]++; M[240] = 2; M[222]++; M[223]++;M[3]++;
				*/
				M[212]--;
				M[252]--;
				robot.Evacuer();
				qte_produite++;
				cout<<"qte produite = "<<qte_produite<<endl;
				cout<<"qte a produire = "<<qte_totale<<endl;
				M[201]++;
				M[240]=2;
                M[222]++;
                M[223]++;
				M[3]++;
				M[261]++;
				display();
			}  

			if(M[260] && M[261]==M[260]){
				/*!
				* \b T260_261:  Evacuation du produit au poste 3
				* \arg  fin de fabrication au poste 3 et Ã©vacuation
				* \arg \b Precondition: M[260] && M[261]==M[260]
				* \arg \b Postcondition: M[201]++; M[240] = 2; M[222]++; M[223]++;M[3]++;
				*/
				M[260]=0;
				M[261]=0;
				
				M[262]++;
				display();
			}  

			if(M[223] && M[203]==0 && M[246]==0 && M[249]==0){
				/*!
				* \b T223_203barre_246barre_249barre: Fin de production d'un type de produit donné  
				* \arg  fin d'évacuation d'un produit au poste 3 
				* \arg \b Precondition:  M[223] && M[203]==0 && M[246]==0 && M[249]==0
				* \arg \b Postcondition: M[224]++; 
				*/
				M[223]--;
				M[224]++;
				display();
			}

			if(M[212] && M[208]>0 && M[251]){
				/*!
				* \b T212_208:  gamme non épuisée
				* \arg  fin de tache au poste 3 
				* \arg \b Precondition:  M[212] && M[208]>0 && M[251]
				* \arg \b Postcondition: M[220]++; M[251]++; 
				*/
				M[212]--;
				M[208]--;
				M[251]--;
				M[220]++;
				M[251]++;
				index1_seq++;
				display();
			}
			if(M[212] && M[241]>0 && M[252]){
				/*!
				* \b T212_241:  gamme non épuisé
				* \arg  fin de tâche au poste 3 
				* \arg \b Precondition:  M[212] && M[241]>0 && M[252]
				* \arg \b Postcondition: M[220]++; M[252]++;
				*/
				M[212]--;
				M[241]--;
				M[252]--;
				M[220]++;
				M[252]++;
				index2_seq++;
				display();
			}

			if(M[220] && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_3){
				/*!
				* \b T220:  Poursuivre la fabrication au poste 3 
				* \arg  La sÃ©quence suivante du produit se fait au poste 3
				* \arg \b Precondition:  M[220] && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_3
				* \arg \b Postcondition: M[210]++; 
				*/

				M[220]--;
				index_seq_post3++;
				M[210]++;
				display();
			}

			// --------- Poste 4 ------------------------------------------------
			if(M[220] && M[4] && M[251] && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_4){
				/*!
				* \b T220bis_4_1:  Deplacement du produit du poste 3 vers le poste 4 qui est libre
				* \arg  La sÃ©quence suivante du produit se fait au poste 4 donc on l'y deplace et poste 4 est libre et on initialise la place memoire M[253] de sequence du produit indexé 1 au poste 4
				* \arg \b Precondition:  M[220] && M[4] && M[251] && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_4
				* \arg \b Postcondition: M[225]++; M[253]++;
				*/

				M[220]--;
				M[4]--;
				M[251]--;
				index_prod_post4 = index1_prod;
				index_seq_post4 = index1_seq;
                cout<<"index_seq = "<<index_seq_post4<<endl;
                cout<<"index_poste = "<<Prod_seqdeposte[index_prod_post4-1][index_seq_post4]<<endl;
				M[225]++;
				M[253]++;
				display();
			}

			if(M[220] && M[4] && M[252] && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_4){
				/*!
				* \b T220bis_4_2:  Deplacement du produit du poste 3 vers le poste 4 qui est libre
				* \arg  La sÃ©quence suivante du produit se fait au poste 4 donc on l'y deplace et le poste 4 est libre et on initialise la place memoire M[254] de sequence du produit indexé 2 au poste 4
				* \arg \b Precondition:  M[220] && M[4] && M[252] && Prod_seqdeposte[index_prod-1][index_seq+1] == POSTE_4
				* \arg \b Postcondition: M[225]++; M[254]++;
				*/
				M[220]--;
				M[4]--;
				M[252]--;
				index_prod_post4 = index2_prod;
				index_seq_post4 = index2_seq;
                cout<<"index_seq = "<<index_seq_post4<<endl;
                cout<<"index_poste = "<<Prod_seqdeposte[index_prod_post4-1][index_seq_post4]<<endl;
				M[225]++;
				M[254]++;
				display();
			}

			if(M[220] && M[4]==0 && debut_bug==false){
				debut_bug = true;
				cout<< "Debut bug poste 4" << endl; 

				cout<< "Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1]  " << Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] << endl;
			}
			if(M[220] && M[4]==0 && Prod_seqdeposte[index_prod_post3-1][index_seq_post3+1] == POSTE_4){
				/*!
				* \b T220bis_4barre:  Deplacement du produit du poste 3 vers le poste 4 
				* \arg  La sÃ©quence suivante du produit se fait au poste 4 qui n'est pas libre
				* \arg \b Precondition:  M[220] && M[4]==0  && Prod_seqdeposte[index_prod-1][index_seq+1] == POSTE_4
				* \arg \b Postcondition: M[226]++;
				*/
				M[220]--;
				M[226]++;
				display();
			}


			if(M[225] && M[214]){
				/*!
				* \b T225_214:  Deplacement du produit du poste 3 vers le poste 4 
				* \arg  La sÃ©quence suivante du produit se fait au poste 4 et on a le robot R2 libre pour effectuer le déplacement du produit
				* \arg \b Precondition:  M[225] && M[214]
				* \arg \b Postcondition: M[213]++;
				*/

				M[225]--;
				M[214]--;
				robot.DeplacerPiece(ROBOT_2,1,4);
				M[213]++;
				display();
			}

			if(M[213] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T213:  Fin de deplacement du produit sur le poste 4
				* \arg  fin le poste 4
				* \arg \b Precondition:  M[213] && robot.FinDeplacerPiece(ROBOT_2);
				* \arg \b Postcondition: M[3]++; M[215]++; M[214]++;
				*/
				M[213]--;
				M[214]++;
				M[215]++;
				M[3]++;
				display();
			}

			if(M[215]){
				/*!
				* \b T215:  fabrication d'un produit au poste 4
				* \arg  fabrication en cours au poste 4
				* \arg \b Precondition: M[215]
				* \arg \b Postcondition: M[216]++;
				*/
				M[215]--;
				robot.FaireTache(Prod_seqdeposte[index_prod_post4-1][index_seq_post4], Prod_dureeparposte[index_prod_post4-1][index_seq_post4]);
                cout << "duree poste=" << Prod_dureeparposte[index_prod_post4-1][index_seq_post4] << endl;
				M[216]++;
				display();
			}


			if(M[216] && robot.TacheFinie(POSTE_4)){
				/*!
				* \b T216:  Fin de la tÃ¢che au poste 4
				* \arg  fin de tÃ¢che au poste 4 
				* \arg \b Precondition:  M[216] && robot.TacheFinie()
				* \arg \b Postcondition: M[217]++; 
				*/
				M[216]--;
				M[217]++;
				display();
			}
			if(M[217] && M[208]==0 && M[253] && M[3]){
				/*!
				* \b T217_208barre:  DÃ©placement du produit du poste 4 vers le poste 3
				* \arg   Le produit est fini et prÃªt Ã  Ãªtre Ã©vacuer
				* \arg \b Precondition:  M[217] && M[208]==0 && M[253] &&  && M[3] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3
				* \arg \b Postcondition: M[229]++; M[251]++;
				*/
				M[217]--;
				M[253]--;
				M[3]--;
				index_prod_post3 = index1_prod;
				index_seq_post3 = index1_seq;
				M[229]++;
				M[251]++;
				display();
			}

			if(M[217] && M[241]==0 && M[254] && M[3]){
				/*!
				* \b T217_241barre:  DÃ©placement du produit du poste 4 vers le poste 3
				* \arg   Le produit est fini et prÃªt Ã  Ãªtre Ã©vacuer
				* \arg \b Precondition:  M[217] && M[241]==0 && M[254] &&  && M[3] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3
				* \arg \b Postcondition: M[229]++; M[252]++;
				*/
				M[217]--;
				M[253]--;
				M[3]--;
				index_prod_post3 = index2_prod;
				index_seq_post3 = index2_seq;
				M[229]++;
				M[252]++;
				display();
			}

			if(M[217] && M[208]==0 && M[253] && M[3]==0){
				/*!
				* \b T217_241barre_3barre:  DÃ©placement du produit du poste 4 vers le poste 3 qui n'est pas libre
				* \arg   Le produit est fini et prÃªt Ã  Ãªtre Ã©vacuer
				* \arg \b Precondition:  M[217] && M[208]==0 && M[253] &&  && M[3]==0 && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3
				* \arg \b Postcondition: M[230]++; M[251]++;
				*/
				M[217]--;
				M[253]--;
				M[230]++;
				M[253]++;
				display();
			}

			if(M[217] && M[241]==0 && M[254] && M[3]==0){
				/*!
				* \b T217_241barre_3barre:  DÃ©placement du produit du poste 4 vers le poste 3 qui n'est pas libre
				* \arg   Le produit est fini et prÃªt Ã  Ãªtre Ã©vacuer
				* \arg \b Precondition:  M[217] && M[241]==0 && M[254] &&  && M[3]==0 && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3
				* \arg \b Postcondition: M[230]++; M[252]++;
				*/
				M[217]--;
				M[254]--;
				M[230]++;
				M[254]++;
				display();
			}

			


			if(M[229] && M[214]){
				/*!
				* \b T229_214:  DÃ©placement du produit du poste 4 vers le poste 3
				* \arg   Le produit est fini et prÃªt Ã  Ãªtre Ã©vacuer et poste 3 libre
				* \arg \b Precondition:  M[229] && M[214]
				* \arg \b Postcondition: M[218]++;
				*/
				M[229]--;
				M[214]--;
				robot.DeplacerPiece(ROBOT_2,4,1);
				M[218]++;
				display();
			}
			

			if(M[218] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T218:  Fin de dÃ©placement du produit du poste 4 vers le poste 3
				* \arg   Le produit est prÃªt Ã  Ãªtre Ã©vacuer
				* \arg \b Precondition:  M[218] && robot.FinDeplacerPiece(ROBOT_2)
				* \arg \b Postcondition: M[212]++; M[214]++; M[4]++;
				*/
				M[218]--;
				M[214]++;
				M[212]++;
				M[4]++;
				display();
			}


			if(M[217] && M[208]>0 && M[253]){
				/*!
				* \b T217_208_253:  Fin de tÃ¢che au poste 4 mais gamme non Ã©puisÃ©e
				* \arg   La tÃ¢che au poste 4 est fini et les produit n'est pas fini
				* \arg \b Precondition:  M[217] && M[208]>0 && M[253]
				* \arg \b Postcondition: M[219]++; M[253]++;
				*/
				M[208]--;
				M[217]--;
				M[253]--;
				index1_seq++;
				M[219]++;
				M[253]++;
				display();
			}

			if(M[217] && M[241]>0 && M[254]){
				/*!
				* \b T217_241:  Fin de tÃ¢che au poste 4 mais gamme non Ã©puisÃ©e
				* \arg   La tÃ¢che au poste 4 est fini et les produit n'est pas fini
				* \arg \b Precondition:  M[217] && M[241]>0 && M[254]
				* \arg \b Postcondition: M[219]++; M[254]++;
				*/
				M[241]--;
				M[217]--;
				M[254]--;
				index2_seq++;
				M[219]++;
				M[254]++;
				display();
			}

			if(M[219] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_4){
				/*!
				* \b T220:  Poursuivre la fabrication au poste 4 
				* \arg  La sÃ©quence suivante du produit se fait au poste 4
				* \arg \b Precondition:  M[219] && Prod_seqdeposte[index_prod-1][index_seq+1] == POSTE_4
				* \arg \b Postcondition: M[215]++; 
				*/

				M[219]--;
				index_seq_post4++;
                cout<<"index_seq = "<<index_seq_post4<<endl;
                cout<<"index_poste = "<<Prod_seqdeposte[index_prod_post4-1][index_seq_post4]<<endl;
				M[215]++;
				display();
			}

			if(M[219] && M[3] && M[253] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3){
				/*!
				* \b T219_3_1:  Deplacement du produit du poste 4 vers le poste 3
				* \arg  fin de tÃ¢che au poste 4 et son deplacement vers le poste 3 qui est libre
				* \arg \b Precondition:  M[219] && M[3] && M[253] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_4
				* \arg \b Postcondition: M[227]++; M[251]++; 
				*/
				M[219]--;
				M[3]--;
				M[253]--;
				index_prod_post3 = index1_prod;
				index_seq_post3 = index1_seq;
				M[227]++;
				M[251]++; 
				display();
			}

			if(M[219] && M[3] && M[254] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3){
				/*!
				* \b T219_3_2:  Deplacement du produit du poste 4 vers le poste 3
				* \arg  fin de tÃ¢che au poste 4 et son deplacement vers le poste 3 qui est libre
				* \arg \b Precondition:  M[219] && M[3] && M[254] && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_4
				* \arg \b Postcondition: M[227]++; M[252]++; 
				*/
				M[219]--;
				M[3]--;
				M[253]--;
				index_prod_post3 = index2_prod;
				index_seq_post3 = index2_seq;
				M[227]++;
				M[252]++; 
				display();
			}

			if(M[219] && M[3]==0 && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_3){
				/*!
				* \b T219_3barre_2:  Deplacement du produit du poste 4 vers le poste 3
				* \arg  fin de tÃ¢che au poste 4 et son deplacement vers le poste 3 qui n'est pas libre
				* \arg \b Precondition:  M[219] && M[3]==0 && Prod_seqdeposte[index_prod_post4-1][index_seq_post4+1] == POSTE_4
				* \arg \b Postcondition: M[228]++;
				*/
				M[219]--;
				M[228]++; 
				display();
			}

			if(M[227] && M[214]){
				/*!
				* \b T227_214:  Deplacement du produit du poste 4 vers le poste 3
				* \arg  fin de tÃ¢che au poste 4 et son deplacement vers le poste 3 qui est libre
				* \arg \b Precondition:  M[227] && M[214]
				* \arg \b Postcondition: M[221]++; 
				*/
				M[227]--;
				M[214]--;
				robot.DeplacerPiece(ROBOT_2,4,1);
				M[221]++;
				display();
			}

			if(M[221] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T221_2:  Fin de deplacement du produit sur le poste 3
				* \arg   La tÃ¢che au poste 4 est fini et les produit va au poste 3 pour la tÃ¢che suivant
				* \arg \b Precondition:  M[221] && robot.FinDeplacerPiece(ROBOT_2)
				* \arg \b Postcondition: M[4]++; M[214]++; M[210]++;
				*/
				M[221]--;
				M[4]++;
				M[214]++;
				M[210]++;
				display();
			}
			if(M[207] && M[209] && M[4] && Prod_seqdeposte[index1_prod-1][index1_seq] == POSTE_4){
				/*!
				* \b T207_209_4:  Ajout d'un produit au poste 4
				* \arg  VÃ©rifie si le poste de dÃ©part de la gamme d'un produit est le poste 4 qui est libre
				* \arg \b Precondition: M[207] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_4 && M[209]
				* \arg \b Postcondition: M[215]++; M[253]++;
				*/
				M[207]--;
				M[209]--;
                M[4]--;
				index_prod_post4 = index1_prod;
				index_seq_post4 = index1_seq;
				robot.AjouterProduit(Prod_seqdeposte[index_prod_post4-1][index_seq_post4], Prod_type[index_prod_post4-1]);
                M[215]++;
				M[253]++;
				display();
			}
            
			if(M[207] && M[242] && M[4] && Prod_seqdeposte[index2_prod-1][index2_seq] == POSTE_4){
				/*!
				* \b T207_242_4:  Ajout d'un produit au poste 4
				* \arg  VÃ©rifie si le poste de dÃ©part de la gamme d'un produit est le poste 4 qui est libre
				* \arg \b Precondition: M[207] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_4 && M[209]
				* \arg \b Postcondition: M[215]++; M[254]++;
				*/
				M[207]--;
				M[242]--;
                M[4]--;
				index_prod_post4 = index2_prod;
				index_seq_post4 = index2_seq;
				robot.AjouterProduit(Prod_seqdeposte[index_prod_post4-1][index_seq_post4], Prod_type[index_prod_post4-1]);
                M[215]++;
				M[254]++;
				display();
			}

			// --------------Appel de la navette pour permutation -------------------------
			if(M[226] && M[228]){
				/*!
				* \b T226_228:  ScÃ©narios de permutation actif
				* \arg  Besoin d'appeller la navette pour permuter le produit au poste 3 avec le produit qui a besoin d'être évacuer au poste 4
				* \arg \b Precondition:  M[226] && M[228]
				* \arg \b Postcondition: M[231]++; 
				*/
				M[226]--;
				M[228]--;
				M[231]++;
				M[257]++;
				display();
			}

			if(M[226] && M[230]){
				/*!
				* \b T226_230:  ScÃ©narios de permutation actif
				* \arg  Besoin d'appeller la navette
				* \arg \b Precondition:  M[226] && M[228]
				* \arg \b Postcondition: M[231]++; 
				*/
				M[226]--;
				M[230]--;
				M[231]++;
				M[258]++;
				display();
			}

			if(M[231] && capteur.get_PS(23)){
				/*!
				* \b T226_230:  Aiguiller la navette vers la zone de travail
				* \arg  Navette dÃ©tectÃ©e Ã  la position PS1
				* \arg \b Precondition:  M[231] && capteur.get_PS(1)
				* \arg \b Postcondition: M[232]++; 
				*/
				M[231]--;
				aiguillage.Droite(1);
				aiguillage.Droite(2);
				M[232]++;
				display();
			}

			if(M[232] && capteur.get_PS(2)){
				/*!
				* \b T226_230:  Arreter la navette devant le poste 3
				* \arg  Navette dÃ©tectÃ©e Ã  la position PS2
				* \arg \b Precondition:  M[232] && capteur.get_PS(2)
				* \arg \b Postcondition: M[233]++;
				*/
				M[232]--;
				cmd.Stop_PS(2);
				M[233]++;
				display();
			}
            
            

			if(M[233] && M[214] && M[251]){
				/*!
				* \b T226_230:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[233] && M[214] && M[251]
				* \arg \b Postcondition: M[234]++; M[255]++;
				*/
				M[233]--;
				M[251]--;
				M[214]--;
				index_prod_shuttle = index1_prod;
				index_seq_shuttle = index1_seq;
				robot.DeplacerPiece(ROBOT_2,1,2);
				M[234]++;
				M[255]++;
				display();
			}

			if(M[233] && M[214] && M[252]){
				/*!
				* \b T226_230:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[233] && M[214] && M[252]
				* \arg \b Postcondition: M[234]++; M[256]++;
				*/
				M[233]--;
				M[252]--;
				M[214]--;
				index_prod_shuttle = index2_prod;
				index_seq_shuttle = index2_seq;
				robot.DeplacerPiece(ROBOT_2,1,2);
				M[234]++;
				M[256]++;
				display();
			}


			if(M[234] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T226_230:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[234] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: M[214]++; M[235]++;
				*/
				M[234]--;
				M[214]++;
				M[235]++;
				display();
			}
			if(M[235] && M[214]){
				/*!
				* \b T226_230:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[235] && M[214]
				* \arg \b Postcondition: ; M[235]++;
				*/
				M[235]--;
				M[214]--;
				robot.DeplacerPiece(ROBOT_2,4,1);
				M[236]++;
				display();
			}
			if(M[236] && M[258] && M[253] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T236_258:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[236] && M[258] && M[253] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[237]++;  M[212]++; M[251]++; M[214]++;
				*/
				M[236]--;
				M[258]--;
				M[253]--;
				M[237]++;
				M[212]++;
				M[251]++;
				M[214]++;
				index_prod_post3 = index_prod_post4;
				index_seq_post3 = index_seq_post4;
				display();
			}
			
			if(M[236] && M[258] && M[254] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T236_258:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[236] && M[258] && M[254] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[237]++;  M[212]++; M[252]++; M[214]++;
				*/
				M[236]--;
				M[258]--;
				M[254]--;
				M[237]++;
				M[212]++;
				M[252]++;
				M[214]++;
				index_prod_post3 = index_prod_post4;
				index_seq_post3 = index_seq_post4;
				display();
			}

			if(M[236] && M[257] && M[253] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T236_257_253:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[236] && M[257] && M[253] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[237]++;  M[214]++; M[251]++; M[210]++;
				*/
				M[236]--;
				M[253]--;
				M[257]--;
				M[237]++;
				M[214]++; 
				M[251]++; 
				M[210]++;
				index_prod_post3 = index_prod_post4;
				index_seq_post3 = index_seq_post4;
				display();
			}

			if(M[236] && M[257] && M[254] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T236_257_253:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[236] && M[257] && M[254] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[237]++;  M[214]++; M[252]++; M[210]++;
				*/
				M[236]--;
				M[254]--;
				M[257]--;
				M[237]++;
				M[214]++; 
				M[252]++; 
				M[210]++;
				index_prod_post3 = index_prod_post4;
				index_seq_post3 = index_seq_post4;
				display();
			}

			if(M[237] && M[214]){
				/*!
				* \b T237_214:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[237] && M[214]
				* \arg \b Postcondition: ; M[238]++;
				*/
				M[237]--;
				M[214]--;
				robot.DeplacerPiece(ROBOT_2,2,4);
				M[238]++;
				display();
			}

			if(M[238] && M[255] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T238_255:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[238] && M[255] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[239]++; M[215]++; M[214]++; M[253]++;
				*/
				M[238]--;
				M[255]--;
				cmd.Ouvrir_PS(2);
				aiguillage.Gauche(1);
				M[239]++; 
				M[215]++; 
				M[214]++; 
				M[253]++;
				index_prod_post4 = index_prod_shuttle;
				index_seq_post4 = index_seq_shuttle;
				display();
			}

			if(M[238] && M[256] && robot.FinDeplacerPiece(ROBOT_2)){
				/*!
				* \b T238_256:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[238] && M[255] && robot.FinDeplacerPiece()
				* \arg \b Postcondition: ; M[239]++; M[215]++; M[214]++; M[253]++;
				*/
				M[238]--;
				M[256]--;
				cmd.Ouvrir_PS(2);
				aiguillage.Gauche(1);
				M[239]++; 
				M[215]++; 
				M[214]++; 
				M[254]++;
				index_prod_post4 = index_prod_shuttle;
				index_seq_post4 = index_seq_shuttle;
				display();
			}
			if(M[239] && capteur.get_PS(6)){
				/*!
				* \b T239:  Deplacer le produit du poste 3 vers la navette
				* \arg  Deplacer le produit du poste 3 vers la navette
				* \arg \b Precondition:  M[239] && capteur.get_PS(6)
				* \arg \b Postcondition: ; 
				*/
				M[239]--;
				aiguillage.Gauche(2);
				display();
			}


			// -------------Fin de production -------------------
            if(M[222]==qte_totale){
				/*!
				* \b T207_209_4:  Ajout d'un produit au poste 4
				* \arg  VÃ©rifie si le poste de dÃ©part de la gamme d'un produit est le poste 4
				* \arg \b Precondition: M[205]==0 && M[203]==0
				* \arg \b Postcondition: M[PlaceFin]++;
				*/
				M[222] = 0;
                M[PlaceFin]++;
				display();
			}
















            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //////////////////////////////////// | Place de fin de Petri ETU | //////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(M[PlaceFin])
            {
                display();
                cout << endl << BOLDCYAN << " --[PETRI TERMINE]--" << RESET << endl;
                cmd.FinPetri();
                while(ros::ok())
                {
                    ros::spinOnce();
                    loop_rate.sleep();
                }
            }
        }

        ros::spinOnce(); //permet aux fonction callback de ros dans les objets d'Ãªtres appelÃ©es
        loop_rate.sleep(); //permet de synchroniser la boucle while. Il attend le temps qu'il reste pour faire le 25Hz (ou la frÃ©quence indiquÃ©e dans le loop_rate)
    }

    return 0;
}