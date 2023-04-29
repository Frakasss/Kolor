/*
void ScanMap()
void SetGameState(GameState newState)
GameState GetGameState()
void InitPlayer()
void InitPlayerPosition()
void NextPlayer()
void Reset()
*/
//################################################################################################################### SCAN MAP
void ScanMap(){
  menuPvp_item=0;
  menuCustom_item=0;
  menuCustom_player=0;
  menuCustom_detail = false;
  menuCustom_detailitem=0;
  menuPauseItem=0;
  selectedWeapon = 0;
  firstRowDisplayed=0;

  for(int i = 0; i<MAP_WIDTH; i++){
    for(int j = 0; j<MAP_HEIGHT; j++){
      if(gb.display.getPixelColor(i+67,j+90)==WHITE){
        map_layout[j][i]=1;
      }
      if(gb.display.getPixelColor(i+67,j+90)==BLACK){
        map_layout[j][i]=0;
      }

      //PVP
      if(menu_Item==0){
        if(gb.display.getPixelColor(i+67,j+90)==RED){
          map_layout[j][i]=6;
          map_settings[0][0]=i;
          map_settings[0][1]=j;
        }
        if(gb.display.getPixelColor(i+67,j+90)==BLUE){
          map_layout[j][i]=7;
          map_settings[1][0]=i;
          map_settings[1][1]=j;
        }
        if(gb.display.getPixelColor(i+67,j+90)==GREEN){
          if(nbOfPlayer>2){
            map_layout[j][i]=8;
            map_settings[2][0]=i;
            map_settings[2][1]=j;
          }else{
            map_layout[j][i]=1;
          }
        }
          
        if(gb.display.getPixelColor(i+67,j+90)==YELLOW){
          if(nbOfPlayer>3){
            map_layout[j][i]=9;
            map_settings[3][0]=i;
            map_settings[3][1]=j;
          }else{
            map_layout[j][i]=1;
          }
        }
      }

      //PVE
      if(menu_Item==1){
        if(gb.display.getPixelColor(i+67,j+90)==RED){
          map_layout[j][i]=6;
          map_settings[0][0]=i;
          map_settings[0][1]=j;
        }
        if(gb.display.getPixelColor(i+67,j+90)==BLUE){
          map_layout[j][i]=7;
          map_settings[1][0]=i;
          map_settings[1][1]=j;
        }
        if(gb.display.getPixelColor(i+67,j+90)==GREEN){
          if(nbOfPlayer>2){
            map_layout[j][i]=8;
            map_settings[2][0]=i;
            map_settings[2][1]=j;
          }else{
            map_layout[j][i]=1;
          }
        }
          
        if(gb.display.getPixelColor(i+67,j+90)==YELLOW){
          if(nbOfPlayer>3){
            map_layout[j][i]=9;
            map_settings[3][0]=i;
            map_settings[3][1]=j;
          }else{
            map_layout[j][i]=1;
          }
        }
      }

      //Custom
      if(menu_Item==2){
        if(gb.display.getPixelColor(i+67,j+90)==RED){
          if(players[0].playerType==2){
            map_layout[j][i]=1;
          }else{
            map_layout[j][i]=6;
            map_settings[0][0]=i;
            map_settings[0][1]=j;            
          }
        }
        if(gb.display.getPixelColor(i+67,j+90)==BLUE){
          if(players[1].playerType==2){
            map_layout[j][i]=1;
          }else{
            map_layout[j][i]=7;
            map_settings[1][0]=i;
            map_settings[1][1]=j;
          }
        }
        if(gb.display.getPixelColor(i+67,j+90)==GREEN){
          if(players[2].playerType==2){
            map_layout[j][i]=1;
          }else{
            map_layout[j][i]=8;
            map_settings[2][0]=i;
            map_settings[2][1]=j;
          }
        }
          
        if(gb.display.getPixelColor(i+67,j+90)==YELLOW){
          if(players[3].playerType==2){
            map_layout[j][i]=1;
          }else{
            map_layout[j][i]=9;
            map_settings[3][0]=i;
            map_settings[3][1]=j;
          }
        }
      }
    }
  }
  InitPlayerPosition();
}
//###################################################################################################################  GAMESTATE SET
void SetGameState(GameState newState){
  currentGameState = newState;
}

//################################################################################################################### GAMESTATE GET
GameState GetGameState(){
  return currentGameState;
}

//################################################################################################################### INIT PLAYER
void InitPlayer(){
  //default initiation
  for(int i = 0; i<MAX_NB_PLAYER; i++){
    players[i].x       = 0;
    players[i].y       = 0;
    players[i].cptAnim = 0;
    players[i].state   = 0;
    players[i].dir     = 2;
    players[i].score   = 0;
    players[i].weapon  = 0;
    players[i].playerType   = 0;

    switch(i){
      case 0:
        strcpy( players[i].userName, "Picasso" );
        players[i].color    = RED;
        players[i].paintValue = 2;
        break;
      case 1:
        strcpy( players[i].userName, "Kandinsky" );
        players[i].color    = BLUE;
        players[i].paintValue = 3;
        break;
      case 2:
        strcpy( players[i].userName, "Van Gogh" );
        players[i].color    = GREEN;
        players[i].paintValue = 4;
        break;
      case 3:
        strcpy( players[i].userName, "Banksy" );
        players[i].color    = ORANGE;
        players[i].paintValue = 5;
        break;
      default:
        strcpy( players[i].userName, "Unknown" );
        players[i].color    = BLACK;
        players[i].paintValue = 99;
        break;
    }

  }
}

//################################################################################################################### INIT MAP WITH PLAYER POS
void InitPlayerPosition()
{
  if(menu_Item==0){
    for(int i = 0; i<nbOfPlayer; i++){
      players[i].x       = map_settings[i][0];
      players[i].y       = map_settings[i][1];
      players[i].cptAnim = 0;
      players[i].state   = 0;
      players[i].dir     = 2;
      players[i].score   = 0;
      players[i].weapon  = 0;
      map_layout[players[i].y][players[i].x] = 6+i;
    }
  }
  
  if(menu_Item==1){
    for(int i = 0; i<nbOfPlayer; i++){
      players[i].x       = map_settings[i][0];
      players[i].y       = map_settings[i][1];
      players[i].cptAnim = 0;
      players[i].state   = 0;
      players[i].dir     = 2;
      players[i].score   = 0;
      players[i].weapon  = 0;
      map_layout[players[i].y][players[i].x] = 6+i;
    }
  }

  if(menu_Item==2){
    for(int i = 0; i<MAX_NB_PLAYER; i++){
      if(players[i].playerType!=2){
        players[i].x       = map_settings[i][0];
        players[i].y       = map_settings[i][1];
        players[i].cptAnim = 0;
        players[i].state   = 0;
        players[i].dir     = 2;
        players[i].score   = 0;
        players[i].weapon  = 0;
        map_layout[players[i].y][players[i].x] = 6+i;
      }
    }
  }
}

//################################################################################################################### NEXT PLAYER
void NextPlayer(){

    autoMove=true;
    anim=0;
    nbOfturn=MAX_NB_OF_TURN;
    areYouReady=false;


    if(menu_Item==0){
      currentPlayer++;
      if(currentPlayer>=nbOfPlayer){currentPlayer=0;}
    }
    
    if(menu_Item==1){
      currentPlayer++;
      if(currentPlayer>=nbOfPlayer){currentPlayer=0;}
    }

    if(menu_Item==2){
      do{
        currentPlayer++;
        if(currentPlayer>=MAX_NB_PLAYER){currentPlayer=0;}
      }while(players[currentPlayer].playerType==2);
    }
    
    menuPauseItem=0;
    selectedWeapon = players[currentPlayer].weapon;
    
    SetGameState(CHECK);

}

//################################################################################################################### RESET GAME
void Reset(){
  menu_Item = 0;
  nbOfPlayer = 4;
  nbOfCPU = 0;
  currentMap = 0;
  
  menu_Item = 0;
  menuPauseItem=0;
  selectedWeapon = 0;
  
  InitPlayerPosition();
  currentPlayer=0;

  podium.fst=0;
  podium.snd=0;
  podium.trd=0;
  podium.fth=0;
}

bool checkPlayerTypes(int a, int b, int c, int d){
  int check=0;
  if(a==0){check++;}
  if(b==0){check++;}
  if(c==0){check++;}
  if(d==0){check++;}
  if(check==0){return false;}
  else{return true;}
}

bool checkPlayerNumber(int a, int b, int c, int d){
  int check=0;
  if(a==2){check++;}
  if(b==2){check++;}
  if(c==2){check++;}
  if(d==2){check++;}
  if(check>2){return false;}
  else{return true;}
}
