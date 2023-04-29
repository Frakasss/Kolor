//################################################################################################################### IA
void IA_LaunchProcessing(){
  SetGameState(IAPROCESSING);
}

//################################################################################################################### IA Processing
void IA_Processing(){
  int posX = 0;
  int posY = 0;
  bool checkCollision = false;
  int bestScore = 0;
  int currentScore = 0;
  int posColor = 0;

  
  //if first, focus on complete the white cells
  if(podium.fst==currentPlayer){
    
    //######################################################check Move UP
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posY--;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          if(posColor==1){currentScore++; }
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_UP);
    }
  
    //######################################################check Move DOWN
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posY++;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          if(posColor==1){currentScore++; }
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_DOWN);
    }
  
    //######################################################check Move LEFT
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posX--;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          if(posColor==1){currentScore++; }
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_LEFT);
    }
    
    //######################################################check Move RIGHT
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posX++;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          if(posColor==1){currentScore++; }
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_RIGHT);
    }
    
    //######################################################check explosion
    if(previousShot[currentPlayer]!=4){
      posX = players[currentPlayer].x;
      posY = players[currentPlayer].y;
      bool doNotCheck= false;
      currentScore=0;
      for(int i = -2; i<3;i++){
        for(int j = -2; j<3;j++){
          doNotCheck= false;
          if(i==posX && j==posY){doNotCheck= true;}
          if(i==-2   && j==-2)  {doNotCheck= true;}
          if(i==-2   && j==2)   {doNotCheck= true;}
          if(i==2    && j==-2)  {doNotCheck= true;}
          if(i==2    && j==2)   {doNotCheck= true;}
          if(doNotCheck==false){
            checkCollision = HasCollision(posX+i, posY+j);
            if(checkCollision==false){
              posColor = PosValue(posX+i, posY+j);
              if(posColor!=players[currentPlayer].paintValue){
                if(posColor==1){currentScore++; }
              }
            }
          }  
        }
      }
      if(currentScore>bestScore){
        bestScore=currentScore;
        SetGameState(EXPLOSE);
      }
    }
  
    //######################################################check Move
    bool continueCheckPath=true;
    bool wasPlayerAlreadyHere=false;
    int tmpBestScore=0;
    int pathToCheck[8];
    int tmpBestPath[8];
    Coord iaPath[8];
  
    for(int i1=0; i1<4; i1++){
      pathToCheck[0]=i1;
      for(int i2=0; i2<4; i2++){
        pathToCheck[1]=i2;
        for(int i3=0; i3<4; i3++){
          pathToCheck[2]=i3;
          for(int i4=0; i4<4; i4++){
            pathToCheck[3]=i4;
            for(int i5=0; i5<4; i5++){
              pathToCheck[4]=i5;
              for(int i6=0; i6<4; i6++){
                pathToCheck[5]=i6;
                for(int i7=0; i7<4; i7++){
                  pathToCheck[6]=i7;
                  for(int i8=0; i8<4; i8++){
                    pathToCheck[7]=i8;

                    //Path to check is built. Let's check the score
                    posX = players[currentPlayer].x;
                    posY = players[currentPlayer].y;
                    continueCheckPath=true;
                    currentScore=0;
                    
                    
                    for(int i=0; i<8; i++){
                      if(continueCheckPath==true){
                        if(pathToCheck[i]==0){posY--;}//0 UP
                        if(pathToCheck[i]==1){posX++;}//1 RIGHT
                        if(pathToCheck[i]==2){posY++;}//2 DOWN
                        if(pathToCheck[i]==3){posX--;}//3 LEFT
                        iaPath[i].x=posX;
                        iaPath[i].y=posY;
                        
                        if(HasCollision(posX, posY)){
                          continueCheckPath=false;
                          currentScore=0;
                        }else{
                          posColor = PosValue(posX, posY);
                          if(posColor!=players[currentPlayer].paintValue){
                            if(posColor==1){//check white only
                              if(i>1){
                                wasPlayerAlreadyHere=false;
                                for(int k=0; k<i-1; k++){
                                  if(iaPath[k].x==posX and iaPath[k].y==posY){
                                    wasPlayerAlreadyHere=true;
                                  }
                                }
                                if(wasPlayerAlreadyHere==false){
                                  currentScore++;
                                }
                              }else{
                                currentScore++;
                              }
                            }
                          }
                        }
                      }
                    }
                    if(currentScore>tmpBestScore){
                      tmpBestScore=currentScore;
                      for(int z=0; z<8; z++){tmpBestPath[z]=pathToCheck[z];}
                    }
                    currentScore=0;
                  }
                }
              }
            }
          }
        }
      }
    }
    for(int z=0; z<8; z++){iapath[z]=tmpBestPath[z];}
    if(tmpBestScore>bestScore){
      bestScore=tmpBestScore;
      SetGameState(PLAY);
    }
  }
//========================================================================================================
  if(bestScore==0){

    //######################################################check Move UP
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posY--;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX,posY);
        if(posColor!=players[currentPlayer].paintValue){
          currentScore++;
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_UP);
    }

    
    
  
    //######################################################check Move DOWN
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posY++;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          currentScore++;
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_DOWN);
    }

  
    //######################################################check Move LEFT
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posX--;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          currentScore++;
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_LEFT);
    }
        
    //######################################################check Move RIGHT
    posX = players[currentPlayer].x;
    posY = players[currentPlayer].y;
    checkCollision = false;
    currentScore=0;
    while(checkCollision == false){
      posX++;
      checkCollision = HasCollision(posX, posY);
      if(checkCollision==false){
        posColor = PosValue(posX, posY);
        if(posColor!=players[currentPlayer].paintValue){
          currentScore++;
        }
      }
    }
    if(currentScore>bestScore){
      bestScore=currentScore;
      SetGameState(MOVE_RIGHT);
    }

    //######################################################check explosion
    if(previousShot[currentPlayer]!=4){
      posX = players[currentPlayer].x;
      posY = players[currentPlayer].y;
      bool doNotCheck= false;
      currentScore=0;
      for(int i = -2; i<3;i++){
        for(int j = -2; j<3;j++){
          doNotCheck= false;
          if(i==posX && j==posY){doNotCheck= true;}
          if(i==-2   && j==-2)  {doNotCheck= true;}
          if(i==-2   && j==2)   {doNotCheck= true;}
          if(i==2    && j==-2)  {doNotCheck= true;}
          if(i==2    && j==2)   {doNotCheck= true;}
          if(doNotCheck==false){
            checkCollision = HasCollision(posX+i, posY+j);
            if(checkCollision==false){
              posColor = PosValue(posX+i, posY+j);
              if(posColor!=players[currentPlayer].paintValue){
                currentScore++;
              }
            }
          }  
        }
      }
      if(currentScore>bestScore){
        bestScore=currentScore;
        SetGameState(EXPLOSE);
      }
    }


    //######################################################check Move
    bool continueCheckPath=true;
    bool wasPlayerAlreadyHere=false;
    int tmpBestScore=0;
    int pathToCheck[8];
    int tmpBestPath[8];
    Coord iaPath[8];
  
    for(int i1=0; i1<4; i1++){
      pathToCheck[0]=i1;
      for(int i2=0; i2<4; i2++){
        pathToCheck[1]=i2;
        for(int i3=0; i3<4; i3++){
          pathToCheck[2]=i3;
          for(int i4=0; i4<4; i4++){
            pathToCheck[3]=i4;
            for(int i5=0; i5<4; i5++){
              pathToCheck[4]=i5;
              for(int i6=0; i6<4; i6++){
                pathToCheck[5]=i6;
                for(int i7=0; i7<4; i7++){
                  pathToCheck[6]=i7;
                  for(int i8=0; i8<4; i8++){
                    pathToCheck[7]=i8;

                    //Path to check is built. Let's check the score
                    posX = players[currentPlayer].x;
                    posY = players[currentPlayer].y;
                    continueCheckPath=true;
                    currentScore=0;
                    
                    
                    for(int i=0; i<8; i++){
                      if(continueCheckPath==true){
                        if(pathToCheck[i]==0){posY--;}//0 UP
                        if(pathToCheck[i]==1){posX++;}//1 RIGHT
                        if(pathToCheck[i]==2){posY++;}//2 DOWN
                        if(pathToCheck[i]==3){posX--;}//3 LEFT
                        iaPath[i].x=posX;
                        iaPath[i].y=posY;
                        
                        if(HasCollision(posX, posY)){
                          continueCheckPath=false;
                          currentScore=0;
                        }else{
                          posColor = PosValue(posX, posY);
                          if(posColor!=players[currentPlayer].paintValue){
                            if(i>1){
                              wasPlayerAlreadyHere=false;
                              for(int k=0; k<i-1; k++){
                                if(iaPath[k].x==posX and iaPath[k].y==posY){
                                  wasPlayerAlreadyHere=true;
                                }
                              }
                              if(wasPlayerAlreadyHere==false){
                                currentScore++;
                              }
                            }else{
                              currentScore++;
                            }
                          }
                        }
                      }
                    }
                    if(currentScore>tmpBestScore){
                      tmpBestScore=currentScore;
                      for(int z=0; z<8; z++){tmpBestPath[z]=pathToCheck[z];}
                    }
                    currentScore=0;
                  }
                }
              }
            }
          }
        }
      }
    }
    for(int z=0; z<8; z++){iapath[z]=tmpBestPath[z];}
    if(tmpBestScore>bestScore){
      bestScore=tmpBestScore;
      SetGameState(PLAY);
    }
  }


  if(GetGameState()==IA){
    SetGameState(PLAY);
  }

  if(GetGameState()==MOVE_UP)   {previousShot[currentPlayer]=0;}
  if(GetGameState()==MOVE_RIGHT){previousShot[currentPlayer]=1; players[currentPlayer].dir=2;}
  if(GetGameState()==MOVE_DOWN) {previousShot[currentPlayer]=2;}
  if(GetGameState()==MOVE_LEFT) {previousShot[currentPlayer]=3; players[currentPlayer].dir=0;}
  if(GetGameState()==EXPLOSE)   {previousShot[currentPlayer]=4;}
  if(GetGameState()==PLAY)      {previousShot[currentPlayer]=5;}
}
