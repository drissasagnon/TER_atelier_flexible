
"use strict";

let DeplacerPieceMsg = require('./DeplacerPieceMsg.js');
let Msg_StopControl = require('./Msg_StopControl.js');
let Capteurs = require('./Capteurs.js');
let RobotJoints = require('./RobotJoints.js');
let Msg_Color = require('./Msg_Color.js');
let Msg_Erreur = require('./Msg_Erreur.js');
let Msg_PinControl = require('./Msg_PinControl.js');
let TacheFinieMsg = require('./TacheFinieMsg.js');
let Msg_ChoixMode = require('./Msg_ChoixMode.js');
let Msg_SwitchControl = require('./Msg_SwitchControl.js');
let Actionneurs = require('./Actionneurs.js');
let Msg_AddProduct = require('./Msg_AddProduct.js');

module.exports = {
  DeplacerPieceMsg: DeplacerPieceMsg,
  Msg_StopControl: Msg_StopControl,
  Capteurs: Capteurs,
  RobotJoints: RobotJoints,
  Msg_Color: Msg_Color,
  Msg_Erreur: Msg_Erreur,
  Msg_PinControl: Msg_PinControl,
  TacheFinieMsg: TacheFinieMsg,
  Msg_ChoixMode: Msg_ChoixMode,
  Msg_SwitchControl: Msg_SwitchControl,
  Actionneurs: Actionneurs,
  Msg_AddProduct: Msg_AddProduct,
};
