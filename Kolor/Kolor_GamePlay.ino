/*
void Gameplay_UpdatePosition()
void Gameplay_Move(String selectedDir)
void Gameplay_Explosion()
void Gameplay_CheckWin()
void Gameplay_CheckNextPlayer()
*/




//################################################################################################################### MOVE (Weapon 2)
void Gameplay_UpdatePosition()
{
  int nextPosX = players[currentPlayer].x;
  int nextPosY = players[currentPlayer].y;

  switch (GetGameState())
  {
    case MOVE_UP: nextPosY --; break;
    case MOVE_DOWN: nextPosY ++; break;
    case MOVE_LEFT: nextPosX --; break;
    case MOVE_RIGHT: nextPosX ++; break;
    default: break;
  }

  if (HasCollision(nextPosX, nextPosY)){
        autoMove=false;
  }else{
    switch(currentPlayer){
      case 0: previousWalkedState = 2; break;
      case 1: previousWalkedState = 3; break;
      case 2: previousWalkedState = 4; break;
      case 3: previousWalkedState = 5; break;
    }

    map_layout[players[currentPlayer].y][players[currentPlayer].x] = previousWalkedState;
    previousWalkedState = map_layout[nextPosY][nextPosX];
    map_layout[nextPosY][nextPosX] = 6+currentPlayer;
    players[currentPlayer].x = nextPosX;
    players[currentPlayer].y = nextPosY;
  }
}


//################################################################################################################### MOVE (Weapon 1)
void Gameplay_Move(String selectedDir){
  int nextPosX = players[currentPlayer].x;
  int nextPosY = players[currentPlayer].y;  

    if(selectedDir=="UP"){nextPosY --; }
    if(selectedDir=="DOWN"){nextPosY ++; }
    if(selectedDir=="LEFT"){nextPosX --; }
    if(selectedDir=="RIGHT"){nextPosX ++;}

  if (HasCollision(nextPosX, nextPosY)){
     //do nothing
  }else{
    switch(currentPlayer){
      case 0: previousWalkedState = 2; break; //RED
      case 1: previousWalkedState = 3; break; //BLUE
      case 2: previousWalkedState = 4; break; //GREEN
      case 3: previousWalkedState = 5; break; //YELLOW
    }

    map_layout[players[currentPlayer].y][players[currentPlayer].x] = previousWalkedState;
    previousWalkedState = map_layout[nextPosY][nextPosX];
    map_layout[nextPosY][nextPosX] = 6+currentPlayer;
    players[currentPlayer].x = nextPosX;
    players[currentPlayer].y = nextPosY;
    nbOfturn--;
    gb.sound.playTick();
  }
}

//################################################################################################################### MOVE (Weapon 3)
void Gameplay_Explosion(){
  anim++;
  int y = players[currentPlayer].y;
  int x = players[currentPlayer].x;

  if(anim==1){
    if(canPaint(y-1, x-1)){map_layout[y-1][x-1] = currentPlayer+2;}
    if(canPaint(y-1, x  )){map_layout[y-1][x  ] = currentPlayer+2;}
    if(canPaint(y-1, x+1)){map_layout[y-1][x+1] = currentPlayer+2;}
    
    if(canPaint(y  , x-1)){map_layout[y  ][x-1] = currentPlayer+2;}
    if(canPaint(y  , x+1)){map_layout[y  ][x+1] = currentPlayer+2;}

    if(canPaint(y+1, x-1)){map_layout[y+1][x-1] = currentPlayer+2;}
    if(canPaint(y+1, x  )){map_layout[y+1][x  ] = currentPlayer+2;}
    if(canPaint(y+1, x+1)){map_layout[y+1][x+1] = currentPlayer+2;} 

    anim++;
  }

  if(anim==2){
    if(canPaint(y-2, x-1)){map_layout[y-2][x-1] = currentPlayer+2;}
    if(canPaint(y-2, x  )){map_layout[y-2][x  ] = currentPlayer+2;}
    if(canPaint(y-2, x+1)){map_layout[y-2][x+1] = currentPlayer+2;}
    
    if(canPaint(y-1, x-2)){map_layout[y-1][x-2] = currentPlayer+2;}
    if(canPaint(y-1, x+2)){map_layout[y-1][x+2] = currentPlayer+2;}
    
    if(canPaint(y  , x-2)){map_layout[y  ][x-2] = currentPlayer+2;}
    if(canPaint(y  , x+2)){map_layout[y  ][x+2] = currentPlayer+2;}
    
    if(canPaint(y+1, x-2)){map_layout[y+1][x-2] = currentPlayer+2;}
    if(canPaint(y+1, x+2)){map_layout[y+1][x+2] = currentPlayer+2;}
    
    if(canPaint(y+2, x-1)){map_layout[y+2][x-1] = currentPlayer+2;}
    if(canPaint(y+2, x  )){map_layout[y+2][x  ] = currentPlayer+2;}
    if(canPaint(y+2, x+1)){map_layout[y+2][x+1] = currentPlayer+2;}      
  }
}

//################################################################################################################### Check win
void Gameplay_CheckWin(){
  int nbOfWhitePixel = 0;
  players[0].score=0;
  players[1].score=0;
  players[2].score=0;
  players[3].score=0;
  
  for (int i=0; i<MAP_HEIGHT; i++){
    for (int j=0; j<MAP_WIDTH; j++){ 
      switch(map_layout[i][j]){
        case 1: nbOfWhitePixel++; break;    //WHITE
        case 2: players[0].score++; break;  //RED
        case 3: players[1].score++; break;  //BLUE
        case 4: players[2].score++; break;  //GREEN
        case 5: players[3].score++; break;  //YELLOW
        default: break;
      }
    }
  }

  //1st
  if(players[3].score>=players[1].score && players[3].score>=players[2].score && players[3].score>=players[0].score){ podium.fst=3;}
  if(players[2].score>=players[1].score && players[2].score>=players[0].score && players[2].score>=players[3].score){ podium.fst=2;}
  if(players[1].score>=players[0].score && players[1].score>=players[2].score && players[1].score>=players[3].score){ podium.fst=1;}
  if(players[0].score>=players[1].score && players[0].score>=players[2].score && players[0].score>=players[3].score){ podium.fst=0;}

  //4th
  if(players[0].score<=players[1].score && players[0].score<=players[2].score && players[0].score<=players[3].score){ podium.fth=0;}
  if(players[1].score<=players[0].score && players[1].score<=players[2].score && players[1].score<=players[3].score){ podium.fth=1;}
  if(players[2].score<=players[1].score && players[2].score<=players[0].score && players[2].score<=players[3].score){ podium.fth=2;}
  if(players[3].score<=players[1].score && players[3].score<=players[2].score && players[3].score<=players[0].score){ podium.fth=3;}

  if(podium.fst==0){
    if(podium.fth==1){podium.snd=2; podium.trd=3;}
    if(podium.fth==2){podium.snd=1; podium.trd=3;}
    if(podium.fth==3){podium.snd=1; podium.trd=2;}
  }
  if(podium.fst==1){
    if(podium.fth==0){podium.snd=2; podium.trd=3;}
    if(podium.fth==2){podium.snd=0; podium.trd=3;}
    if(podium.fth==3){podium.snd=0; podium.trd=2;}
  }
  if(podium.fst==2){
    if(podium.fth==1){podium.snd=0; podium.trd=3;}
    if(podium.fth==0){podium.snd=1; podium.trd=3;}
    if(podium.fth==3){podium.snd=0; podium.trd=1;}
  }
  if(podium.fst==3){
    if(podium.fth==1){podium.snd=0; podium.trd=2;}
    if(podium.fth==2){podium.snd=0; podium.trd=1;}
    if(podium.fth==0){podium.snd=1; podium.trd=2;}
  }

  if(players[podium.snd].score<players[podium.trd].score){
    int tmp = podium.trd;
    podium.trd = podium.snd;
    podium.snd = tmp;
  }

  if(nbOfWhitePixel==0){SetGameState(WIN);}
  else{
    if(menu_Item==0){
      SetGameState(RUREADY);
    }

    if(menu_Item==1){
      if(currentPlayer==0){SetGameState(RUREADY);}
      else{SetGameState(IA);}
    }

    if(menu_Item==2){
      if(players[currentPlayer].playerType==0){SetGameState(RUREADY);}
      if(players[currentPlayer].playerType==1){SetGameState(IA);}
    }    
  }
}

//################################################################################################################### NEXT PLAYER
void Gameplay_CheckNextPlayer(){
  switch (GetGameState())
  {
    case LOADMAP:
      currentPlayer=4;
      NextPlayer();
      break;
    case EXPLOSE: 
      if(anim==2){NextPlayer();}
      break;
    case PLAY: 
      if(nbOfturn==0){NextPlayer();}
      //if(players[currentplayer].playerType==2){NextPlayer();}
      //if currentplayer is disabled, nextplayer
      break;
    case MOVE_UP: 
    case MOVE_DOWN: 
    case MOVE_LEFT: 
    case MOVE_RIGHT: 
      if(autoMove==false){NextPlayer();}
      break;
    default: break;
  }
}
