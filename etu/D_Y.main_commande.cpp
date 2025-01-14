/*#########################################################################
##   ___ __ __                      __                       ____        ##
##    | |_ |__)   /\ |_ _ |o _  _  |_ | _   o|_ | _    __   |_  | /  \   ##
##    | |__| \   /--\|_(-`||(-`|   |  |(-`><||_)|(-`        |__ | \__/   ##
##                                                                       ##
##########################################################################*/

/*!
 * \file XXX_XXX_main_commande.cpp
 * \brief code créé pour TER atelier flexible
 * \author Team XXX_XXX (N7 2020-2021)
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
int nb_type_prod; // nombre de types de produits
int index_prod; // indice indiquant le type de produit



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

  cmd.activateShuttleManagerDisplay();
	// cmd.activateAutoRunSimu();
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
	nb_type_prod = Prod_type.size();
	index_prod = 0; // initialisation pour pointer sur le premier produit de la liste des types de produits
	index_seq = 0; // initialisation pour pointer sur la première sequence de la gamme
	M[205] = nb_type_prod;
	


    ///////////////////////////////////////////////////////////////////
    /////////////////////  |  FIN INIT ETU  |  ////////////////////
    ///////////////////////////////////////////////////////////////////

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
				* \arg \b Postcondition: M[101]++; M[201]++
				*/
				M[0]--;
				//ACTION….
				aiguillage.Gauche(1);
				aiguillage.Droite(2);
				aiguillage.Gauche(3);
				aiguillage.Gauche(10);
				aiguillage.Gauche(11);
				aiguillage.Gauche(12);
				//cmd.Stop_PS(2);
				M[101]++;
				M[201]++;
				display();
            }

			if(M[101] && capteur.get_PS(6)){
				/*!
				* \b T2:  aiguillage A02 mise en place
				* \arg  positionnement de aiguillage 2 à gauche pour laisser sortie la navette de la zone de travail 
				* \arg \b Precondition: M[101] && capteur.get_PS(6)
				* \arg \b Postcondition: M[102]++;
				*/
				M[101]--;
				aiguillage.Gauche(2);
				M[102]++;
				display();
			}

		// -----------------------------------------------------------------------
		// Section production 
		// -----------------------------------------------------------------------

			if(M[205] && (M[203]==0)){
				/*!
				* \b T205:  Lancement d'un nouveau type produit
				* \arg  Vérifie si la fabrication d'un type de produit est terminer pour pouvoir lancer le prochain
				* \arg \b Precondition: M[205] && (M[203]==0)
				* \arg \b Postcondition: M[204]=index_prod + 1;
				*/
				M[205]--;
				index_prod++;
				M[204]=index_prod;
				display();
			}

			if(M[204]>0){
				/*!
				* \b T204:  mise à jour de la quantité à produire
				* \arg  Charger dans le compteur de produit a fabriquer avec la nouvelle quantité
				* \arg \b Precondition: M[204]>0
				* \arg \b Postcondition: M[203]=Prod_qte(M[204]-1); M[206]++;
				*/
				
				M[203]=Prod_qte(M[204]-1);
				M[206]++;
				M[204]--;
				display();
			}

			if(M[201] && M[203]>0){
				/*!
				* \b T201_203:  lancement de la production d'une unité d'un type de produit.
				* \arg  Après vérification que la quantité à produire n'est pas atteinte
				* \arg \b Precondition: M[201] && M[203]
				* \arg \b Postcondition: M[202]++;
				*/

				M[201]--;
				M[203]--;
				M[207]++;
				display();
			}
			if(M[206]){
				/*!
				* \b T4:  Initialisation du nombre de séquence dans une gamme
				* \arg  Vérifie si le produit est fabriquer pour pouvoir lancer le prochain en initialisant le nouveau nombre de séquence
				* \arg \b Precondition: M[206]
				* \arg \b Postcondition: M[201]++;
				*/
				M[206]--;
				M[208] = Prod_seqdeposte[index_prod-1].size();
				display();
			}

			if(M[208]>0){
				/*!
				* \b T208:  initialisation de pour pointer sur la première sequence d'une gamme
				* \arg  
				* \arg \b Precondition: M[208]>0
				* \arg \b Postcondition: M[201]++;
				*/
				M[208]--;
				index_seq = 0;
				M[209]++;
				display();
			}
			// ---- Poste 3 ------------------------------------------------
			if(M[207] && M[209] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_3){
				/*!
				* \b T207_209:  Ajout d'un produit au poste 3
				* \arg  Vérifie si le poste de départ de la gamme d'un produit est le poste 3
				* \arg \b Precondition: M[207] && Prod_seqdeposte[index_prod-1][index_seq] == POSTE_3 , M[209]
				* \arg \b Postcondition: M[201]++;
				*/
				M[207]--;
				M[209]--;
				robot.AjouterProduit(Prod_seqdeposte[index_prod-1][index_seq], Prod_type[index_prod-1]);
                M[210]++;
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
				robot.FaireTache(Prod_seqdeposte[index_prod-1][index_seq], Prod_dureeparposte[index_prod-1][index_seq]);
                cout << "duree poste=" << Prod_dureeparposte[index_prod-1][index_seq] << endl;
				M[211]++;
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

		ros::spinOnce(); //permet aux fonction callback de ros dans les objets d'êtres appelées
		loop_rate.sleep(); //permet de synchroniser la boucle while. Il attend le temps qu'il reste pour faire le 25Hz (ou la fréquence indiquée dans le loop_rate)
	}

	return 0;
}
