
"use strict";

let Msg_AddProduct = require('./Msg_AddProduct.js');
let Msg_Color = require('./Msg_Color.js');
let Msg_PinControl = require('./Msg_PinControl.js');
let Msg_StopControl = require('./Msg_StopControl.js');
let RobotJoints = require('./RobotJoints.js');
let Actionneurs = require('./Actionneurs.js');
let Msg_ChoixMode = require('./Msg_ChoixMode.js');
let TacheFinieMsg = require('./TacheFinieMsg.js');
let Msg_SwitchControl = require('./Msg_SwitchControl.js');
let DeplacerPieceMsg = require('./DeplacerPieceMsg.js');
let Capteurs = require('./Capteurs.js');
let Msg_Erreur = require('./Msg_Erreur.js');

module.exports = {
  Msg_AddProduct: Msg_AddProduct,
  Msg_Color: Msg_Color,
  Msg_PinControl: Msg_PinControl,
  Msg_StopControl: Msg_StopControl,
  RobotJoints: RobotJoints,
  Actionneurs: Actionneurs,
  Msg_ChoixMode: Msg_ChoixMode,
  TacheFinieMsg: TacheFinieMsg,
  Msg_SwitchControl: Msg_SwitchControl,
  DeplacerPieceMsg: DeplacerPieceMsg,
  Capteurs: Capteurs,
  Msg_Erreur: Msg_Erreur,
};
