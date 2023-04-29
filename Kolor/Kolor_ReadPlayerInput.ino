/*
void ReadPlayerInput()
void ReadPlayerInput_Creator()
void ReadPlayerInput_Intro()
void ReadPlayerInput_Menu()
void ReadPlayerInput_MenuPVP()
void ReadPlayerInput_MenuPVE()
void ReadPlayerInput_MenuCustom()
void ReadPlayerInput_Credits()
void ReadPlayerInput_Ready()
void ReadPlayerInput_Game()
void ReadPlayerInput_Pause()
void ReadPlayerInput_Win()
*/

//############################################################################################# PLAYER INPUT
void ReadPlayerInput()
{
  if (gb.buttons.pressed(BUTTON_MENU)){
    //Reset();
  }
}

//############################################################################################# GAMEMAKERS
void ReadPlayerInput_Creator(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(TITLESCREEN);
  }
  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(TITLESCREEN);
  }
}

//############################################################################################# TITLESCREEN
void ReadPlayerInput_Intro(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(MENU);
  }
  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(GAMEMAKERS);
  }
}

//############################################################################################# MENU
void ReadPlayerInput_Menu(){
  if(gb.buttons.pressed(BUTTON_DOWN)){
    menu_Item++;
    if(menu_Item>3){menu_Item=3;}
  }

  if(gb.buttons.pressed(BUTTON_UP)){
    menu_Item--;
    if(menu_Item<0){menu_Item=0;}
  }

  if(gb.buttons.pressed(BUTTON_A)){
    switch(menu_Item){
      case 0:
        SetGameState(MENU_PVP);
        break;
      case 1:
        SetGameState(MENU_PVE);
        break;
      case 2:
        SetGameState(MENU_CUSTOM);
        break;
      case 3:
        SetGameState(CREDITS);
        break;
      default:
        break;
    }
  }
}

//############################################################################################# MENU PVP
void ReadPlayerInput_MenuPVP(){
  if(gb.buttons.pressed(BUTTON_A)){
    menuPvp_item++;
    if(menuPvp_item>1){
      SetGameState(LOADMAP);
    }
  }

  if(gb.buttons.pressed(BUTTON_B)){
    menuPvp_item--;
    if(menuPvp_item<0){
      menuPvp_item=0;
      SetGameState(MENU);
    }
  }

  if(menuPvp_item==0){
    if(gb.buttons.pressed(BUTTON_DOWN)){
      nbOfPlayer--;
      if(nbOfPlayer<2){nbOfPlayer=2;}
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      nbOfPlayer++;
      if(nbOfPlayer>MAX_NB_PLAYER){nbOfPlayer=MAX_NB_PLAYER;}
    }    
  }

  if(menuPvp_item==1){
    if(gb.buttons.pressed(BUTTON_LEFT)){
      selectedMap--;
      if(selectedMap<0){selectedMap=0;}
    }
    if(gb.buttons.pressed(BUTTON_RIGHT)){
      selectedMap++;
      if(selectedMap>NB_MAP-1){selectedMap=NB_MAP-1;}
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      selectedMap=selectedMap-4;
      if(selectedMap<0){selectedMap=selectedMap+4;}
    }
    if(gb.buttons.pressed(BUTTON_DOWN)){
      selectedMap=selectedMap+4;
      if(selectedMap>NB_MAP-1){selectedMap=selectedMap-4;}
    }
    if(selectedMap/4<firstRowDisplayed){firstRowDisplayed--;}
    if(selectedMap/4>firstRowDisplayed+2){firstRowDisplayed++;}
  }
}

//############################################################################################# MENU PVE
void ReadPlayerInput_MenuPVE(){
  if(gb.buttons.pressed(BUTTON_A)){
    menuPvp_item++;
    if(menuPvp_item>1){
      SetGameState(LOADMAP);
    }
  }

  if(gb.buttons.pressed(BUTTON_B)){
    menuPvp_item--;
    if(menuPvp_item<0){
      menuPvp_item=0;
      SetGameState(MENU);
    }
  }

  if(menuPvp_item==0){
    if(gb.buttons.pressed(BUTTON_DOWN)){
      nbOfPlayer--;
      if(nbOfPlayer<2){nbOfPlayer=2;}
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      nbOfPlayer++;
      if(nbOfPlayer>MAX_NB_PLAYER){nbOfPlayer=MAX_NB_PLAYER;}
    }    
  }

  if(menuPvp_item==1){
    if(gb.buttons.pressed(BUTTON_LEFT)){
      selectedMap--;
      if(selectedMap<0){selectedMap=0;}
    }
    if(gb.buttons.pressed(BUTTON_RIGHT)){
      selectedMap++;
      if(selectedMap>NB_MAP-1){selectedMap=NB_MAP-1;}
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      selectedMap=selectedMap-4;
      if(selectedMap<0){selectedMap=selectedMap+4;}
    }
    if(gb.buttons.pressed(BUTTON_DOWN)){
      selectedMap=selectedMap+4;
      if(selectedMap>NB_MAP-1){selectedMap=selectedMap-4;}
    }
    if(selectedMap/4<firstRowDisplayed){firstRowDisplayed--;}
    if(selectedMap/4>firstRowDisplayed+2){firstRowDisplayed++;}
  }
}

//############################################################################################# MENU CUSTOM
void ReadPlayerInput_MenuCustom(){
  if(menuCustom_detail==false){
    if(gb.buttons.pressed(BUTTON_A)){
      if(menuCustom_player==4){
        if(checkPlayerNumber(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==true && checkPlayerTypes(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==true){
          menuCustom_item++;
          if(menuCustom_item>1){
            SetGameState(LOADMAP);
          }
        }
      }
    }
  
    if(gb.buttons.pressed(BUTTON_B)){
      menuCustom_item--;
      if(menuCustom_item<0){
        menuCustom_item=0;
        SetGameState(MENU);
      }
    }
  }

  if(menuCustom_item==0){
    if(menuCustom_detail==false){
      if(gb.buttons.pressed(BUTTON_UP)){
        menuCustom_player--;
        if(menuCustom_player<0){menuCustom_player=0;}
      }
      if(gb.buttons.pressed(BUTTON_DOWN)){
        menuCustom_player++;
        if(menuCustom_player>4){menuCustom_player=4;}
        if(menuCustom_player==4){
          if(checkPlayerNumber(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==false){
            menuCustom_player=3;
          }else if(checkPlayerTypes(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==false){
            menuCustom_player=3;
          }
        }
      }
      if(gb.buttons.pressed(BUTTON_A)){
        menuCustom_detail=true;
      }
    }

    if(menuCustom_detail==true){
      if(gb.buttons.pressed(BUTTON_UP)){
        menuCustom_detailitem--;
        if(menuCustom_detailitem<0){menuCustom_detailitem=0;}
      }
      if(gb.buttons.pressed(BUTTON_DOWN)){
        menuCustom_detailitem++;
        if(menuCustom_detailitem>2){menuCustom_detailitem=2;}
      }


      if(menuCustom_detailitem==0){
        if(gb.buttons.pressed(BUTTON_LEFT)){
          players[menuCustom_player].playerType--;
          if(players[menuCustom_player].playerType<0){players[menuCustom_player].playerType=2;}
        }
        if(gb.buttons.pressed(BUTTON_RIGHT)){
          players[menuCustom_player].playerType++;
          if(players[menuCustom_player].playerType>2){players[menuCustom_player].playerType=0;}
        }
      }

      if(menuCustom_detailitem==1){
        if(gb.buttons.pressed(BUTTON_A)){          
          gb.gui.keyboard("Player name?", players[menuCustom_player].userName, 9);
        }
      }

      if(menuCustom_detailitem==2){
        if(gb.buttons.pressed(BUTTON_A)){
          menuCustom_detailitem=0;
          menuCustom_detail=false;
        }
      }
    }
  }

  
  if(menuCustom_item==1){
    if(gb.buttons.pressed(BUTTON_LEFT)){
      selectedMap--;
      if(selectedMap<0){selectedMap=0;}
    }
    if(gb.buttons.pressed(BUTTON_RIGHT)){
      selectedMap++;
      if(selectedMap>NB_MAP-1){selectedMap=NB_MAP-1;}
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      selectedMap=selectedMap-4;
      if(selectedMap<0){selectedMap=selectedMap+4;}
    }
    if(gb.buttons.pressed(BUTTON_DOWN)){
      selectedMap=selectedMap+4;
      if(selectedMap>NB_MAP-1){selectedMap=selectedMap-4;}
    }
    if(selectedMap/4<firstRowDisplayed){firstRowDisplayed--;}
    if(selectedMap/4>firstRowDisplayed+2){firstRowDisplayed++;}
  }

  

}

//############################################################################################# CREDITS
void ReadPlayerInput_Credits(){
  if (gb.buttons.pressed(BUTTON_B)){
      SetGameState(MENU);
    }   
}


//############################################################################################# PAUSE
void ReadPlayerInput_Ready(){
  if (gb.buttons.pressed(BUTTON_A)){
      SetGameState(PLAY);
    }   
}


//############################################################################################# IA (debug)
void ReadPlayerInput_IA(){
  if (gb.buttons.pressed(BUTTON_A)){
      debugF11=true;
  } 
}

//############################################################################################# GAME
void ReadPlayerInput_Game(){
  bool checkButtons=true;
  //if menu_Item==0 (PVP)
  if(menu_Item==0){checkButtons=true;}

  //if menu_Item==1 (PVE)
  if(menu_Item==1){
    if(currentPlayer==0){checkButtons=true;}
    if(currentPlayer>0){checkButtons=false;}
  }
  
  //if menu_Item==2 (CUSTOM)
  if(menu_Item==2){
    if(players[currentPlayer].playerType==0){checkButtons=true;} //(human)
    if(players[currentPlayer].playerType==1){checkButtons=false;} //(cpu)
  }

  if(checkButtons==true){
    if (gb.buttons.pressed(BUTTON_MENU)){
      menuPauseItem=0;
      selectedWeapon = players[currentPlayer].weapon;
      SetGameState(PAUSE);
    }
  
    if(menuPauseItem==0){
      if(players[currentPlayer].weapon==0){
        if (gb.buttons.pressed(BUTTON_UP)){
          Gameplay_Move("UP");
        }
        else if (gb.buttons.pressed(BUTTON_DOWN)){
          Gameplay_Move("DOWN");
        }
        else if (gb.buttons.pressed(BUTTON_LEFT)){
          players[currentPlayer].dir=0;
          Gameplay_Move("LEFT");
        }
        else if (gb.buttons.pressed(BUTTON_RIGHT)){
          players[currentPlayer].dir=2;
          Gameplay_Move("RIGHT");
        }
      }
      
      if(players[currentPlayer].weapon==1){
        if (gb.buttons.pressed(BUTTON_UP)){
          SetGameState(MOVE_UP);
        }
        else if (gb.buttons.pressed(BUTTON_DOWN)){
          SetGameState(MOVE_DOWN);
        }
        else if (gb.buttons.pressed(BUTTON_LEFT)){
          players[currentPlayer].dir=0;
          SetGameState(MOVE_LEFT);
        }
        else if (gb.buttons.pressed(BUTTON_RIGHT)){
          players[currentPlayer].dir=2;
          SetGameState(MOVE_RIGHT);
        }
      }
    
      if(players[currentPlayer].weapon==2){
        if (gb.buttons.pressed(BUTTON_B)){
          SetGameState(EXPLOSE);
        }
      } 
    
      if(players[currentPlayer].weapon==3){
        if (gb.buttons.pressed(BUTTON_B)){
          NextPlayer();
        }
      }
    }else{
      if (gb.buttons.pressed(BUTTON_B)){
        
        Reset();
        SetGameState(MENU);
      }
    }
  }

  if(checkButtons==false){
    //IA, MOVE
    switch(iapath[8-nbOfturn]){
      case 0: Gameplay_Move("UP"); break;
      case 1: players[currentPlayer].dir=2; Gameplay_Move("RIGHT"); break;
      case 2: Gameplay_Move("DOWN"); break;
      case 3: players[currentPlayer].dir=0; Gameplay_Move("LEFT"); break;
    }
  }
}

//############################################################################################# PAUSE
void ReadPlayerInput_Pause(){
  if (gb.buttons.pressed(BUTTON_MENU) || gb.buttons.pressed(BUTTON_B)){
    SetGameState(PLAY);
  }
  
  if (gb.buttons.pressed(BUTTON_UP)){
    menuPauseItem=0;
  }
  if (gb.buttons.pressed(BUTTON_DOWN)){
    menuPauseItem=1;
  } 

  if(menuPauseItem==0 && nbOfturn==MAX_NB_OF_TURN){
    if (gb.buttons.pressed(BUTTON_LEFT)){
      selectedWeapon--;
      if(selectedWeapon<0){selectedWeapon=0;}
    }
    if (gb.buttons.pressed(BUTTON_RIGHT)){
      selectedWeapon++;
      if(selectedWeapon>3){selectedWeapon=3;}
    }   
  }

  if(gb.buttons.pressed(BUTTON_A)){
    if(menuPauseItem==0){
      players[currentPlayer].weapon = selectedWeapon;
      SetGameState(PLAY);
    }
    if(menuPauseItem==1){
      SetGameState(PLAY);
    }
  }
}

//############################################################################################# PODIUM
void ReadPlayerInput_Win(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(SEEMAP);
  }
  if(gb.buttons.pressed(BUTTON_B)){
    Reset();
    SetGameState(MENU);
  }
}

//############################################################################################# SEEMAP
void ReadPlayerInput_SeeMap(){
  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(WIN);
  }
}
