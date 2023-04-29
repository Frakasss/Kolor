/*
void Display_Creator()
void Display_Titlescreen()
void Display_Menu()
void Display_MenuPVP()
void Display_MenuPVE()
void Display_MenuCustom()
void Display_Loadmap()
void Display_Credits()
void display_BackgroundTheme(int theme)
void Display_Game()
void Display_Ready()
void Display_WeaponMenu()
void Display_Podium()
void Display_TextPlay()
void Display_SelectedWeapon()
void Display_Buttons()
void Display_Congrats()

void printPlayer(int posx,int posy, int userId, int menuCustom_player)
void printChar(int posx, int posy, int userId)
void printDisabled(int posx,int posy)
void printCpu(int posx, int posy, int userId)
void printName(int posx, int posy, int userId)
void setCursorPositionCenter(int txtLength,int y, Color txtColor)
void setCursorPositionCenter(int txtLength,int x, int y, Color txtColor)
*/

//################################################################################################################### CREATOR
void Display_Creator(){
  Image GameMakers(GamemakersData);
  gb.display.drawImage(0,0,GameMakers,160,128); 
}

//################################################################################################################### TITLESCREEN
void Display_Titlescreen(){
  Image Titlescreen(GAMETITLE);
  gb.display.drawImage(0,0,Titlescreen); 
}

//################################################################################################################### MENU
void Display_Menu(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(2);

  //==============================================================Player vs. Player : 17
  if(menu_Item==0){
    setCursorPositionCenter(strlen("Player vs. Player"), 46, BLACK);
    gb.display.print("Player vs. Player");
    gb.display.drawRect(20,40,120,18);
  }else{
    setCursorPositionCenter(strlen("Player vs. Player"), 46, GRAY);
    gb.display.print("Player vs. Player");
    gb.display.drawRect(20,40,120,18);
  }
  
  //==============================================================Player vs. CPU : 14
  if(menu_Item==1){
    setCursorPositionCenter(strlen("Player vs. CPU"), 66, BLACK);
    gb.display.print("Player vs. CPU");
    gb.display.drawRect(20,60,120,18);
  }else{
    setCursorPositionCenter(strlen("Player vs. CPU"), 66, GRAY);
    gb.display.print("Player vs. CPU");
    gb.display.drawRect(20,60,120,18);
  }

  //==============================================================Custom Game : 11
  if(menu_Item==2){
    setCursorPositionCenter(strlen("Custom Game"), 86, BLACK);
    gb.display.print("Custom Game");
    gb.display.drawRect(20,80,120,18);
  }else{
    setCursorPositionCenter(strlen("Custom Game"), 86, GRAY);
    gb.display.print("Custom Game");
    gb.display.drawRect(20,80,120,18);
  }

  //==============================================================Credits : 7
  if(menu_Item==3){
    setCursorPositionCenter(strlen("Credits"), 106, BLACK);
    gb.display.print("Credits");
    gb.display.drawRect(20,100,120,18);
  }else{
    setCursorPositionCenter(strlen("Credits"), 106, GRAY);
    gb.display.print("Credits");
    gb.display.drawRect(20,100,120,18);
  }
}

//################################################################################################################### MENU PVP
void Display_MenuPVP(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(1);

  int posx = 0;
  int posy = 0;

  int y = 34;
  
  setCursorPositionCenter(strlen("PLAYER vs. PLAYER"),y,BLACK);
  gb.display.print("PLAYER vs. PLAYER");

  y=y+9;
  /*
  gb.display.setColor(BLACK);
  gb.display.drawRect(18,y+10,124,64);
  gb.display.setColor(WHITE);
  gb.display.fillRect(19,y+11,122,62);//141
  */
  if(menuPvp_item==0){
    setCursorPositionCenter(strlen("Select number of Players"),y,GRAY);
    gb.display.print("Select number of Players");

    int n = 15;
    if(nbOfPlayer==4){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.drawRect(21,y+10,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+16);
    gb.display.print("4 players");
    printChar(31+(n*3), y+18, 3);
    printChar(31+(n*2), y+18, 2);
    printChar(31+(n*1), y+18, 1);
    printChar(31+(n*0), y+18, 0);

    if(nbOfPlayer==3){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}    
    gb.display.drawRect(21,y+30,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+36);
    gb.display.print("3 players");
    printChar(31+(n*2), y+38, 2);
    printChar(31+(n*1), y+38, 1);
    printChar(31+(n*0), y+38, 0);

    if(nbOfPlayer==2){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}    
    gb.display.drawRect(21,y+50,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+56);
    gb.display.print("2 players"); 
    printChar(31+(n*1), y+58, 1);
    printChar(31+(n*0), y+58, 0);
/*version1
    Image less(POINTERLEFT);
    Image more(POINTERRIGHT);
    gb.display.drawImage(19+2,   y+11+31-2, less, 3+(nbOfPlayer/3)*-3,0,3,6);
    gb.display.drawImage(141-2-3,y+11+31-2, more, (nbOfPlayer/4)*3,   0,3,6);

    printChar(55,  83+(nbOfPlayer/3)*-20,0);
    printName(55,  83+(nbOfPlayer/3)*-20,0);
    
    printChar(105, 83+(nbOfPlayer/3)*-20,1);
    printName(105, 83+(nbOfPlayer/3)*-20,1);
    
    if(nbOfPlayer>2){
      printChar(80+(nbOfPlayer/4)*-25,  93, 2);
      printName(80+(nbOfPlayer/4)*-25,  93,1);
    }
    
    if(nbOfPlayer>3){
      printChar(105, 93, 3);
      printName(105, 93, 3);
    }
*/
  }

  if(menuPvp_item==1){
    setCursorPositionCenter(strlen("Select Map"),y,GRAY);
    gb.display.print("Select Map");
    
    if(NB_MAP>12){
      int maxHeight=63;
      int cur = (maxHeight-2)/((NB_MAP/4)-2);
      gb.display.setColor(GRAY);
      gb.display.fillRect(134,y+11,7,maxHeight);
      gb.display.setColor(DARKGRAY);
      gb.display.fillRect(135,y+12+cur*firstRowDisplayed,5,cur);
    }
    
    Image Maps(MAP_DATA);
    posx = 21;
    posy = y+13+(firstRowDisplayed*-1*20);
    for(int i=0;i<NB_MAP;i++){
      if(i==selectedMap){
        gb.display.setColor(RED);
        gb.display.drawRect(posx-1,posy-1,28,20);
      }
      
      if(i/4>=firstRowDisplayed && i/4<=firstRowDisplayed+2){
        gb.display.drawImage(posx,posy,Maps,0+(i%4)*26,0+(i/4)*18,26,18);
      }
      posx=posx+28;
      if(i%4==3){
        posx=21;
        posy=posy+20;
      }
    }
  }

}

//################################################################################################################### MENU PVE
void Display_MenuPVE(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(1);

  int posx = 0;
  int posy = 0;

  int y = 34;
  setCursorPositionCenter(strlen("PLAYER vs. CPUs"),y,BLACK);
  gb.display.print("PLAYER vs. CPUs");

  y=y+9;
/*version1
  gb.display.setColor(BLACK);
  gb.display.drawRect(18,y+10,124,64);
  gb.display.setColor(WHITE);
  gb.display.fillRect(19,y+11,122,62);//141
*/  

  if(menuPvp_item==0){
    setCursorPositionCenter(strlen("Select number of Computers"),y,GRAY);
    gb.display.print("Select number of Computers");

    int n = 15;
    if(nbOfPlayer==4){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.drawRect(21,y+10,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+16);
    gb.display.print("4 players");
    printCpu( 31+(n*3), y+19, 3);
    printCpu( 31+(n*2), y+19, 2);
    printCpu( 31+(n*1), y+19, 1);
    printChar(31+(n*0), y+18, 0);

    if(nbOfPlayer==3){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}    
    gb.display.drawRect(21,y+30,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+36);
    gb.display.print("3 players");
    printCpu( 31+(n*2), y+39, 2);
    printCpu( 31+(n*1), y+39, 1);
    printChar(31+(n*0), y+38, 0);

    if(nbOfPlayer==2){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}    
    gb.display.drawRect(21,y+50,118,17);
    gb.display.setCursorX(100);
    gb.display.setCursorY(y+56);
    gb.display.print("2 players"); 
    printCpu( 31+(n*1), y+59, 1);
    printChar(31+(n*0), y+58, 0);

  
    
/*version1
    Image less(POINTERLEFT);
    Image more(POINTERRIGHT);
    gb.display.drawImage(19+2,   y+11+31-2, less, 3+(nbOfPlayer/3)*-3,0,3,6);
    gb.display.drawImage(141-2-3,y+11+31-2, more, (nbOfPlayer/4)*3,   0,3,6);

    printChar(55,  83+(nbOfPlayer/3)*-20, 0);
    printName(55,  83+(nbOfPlayer/3)*-20, 0);
    
    printCpu( 105, 83+(nbOfPlayer/3)*-20, 1);
    printName(105, 83+(nbOfPlayer/3)*-20, 1);
    
    if(nbOfPlayer>2){
      printCpu( 80+(nbOfPlayer/4)*-25,  93, 2);
      printName(80+(nbOfPlayer/4)*-25,  93, 2);
    }
    
    if(nbOfPlayer>3){
      printCpu( 105, 93, 3);
      printName(105, 93, 3);
    }*/
  }

  if(menuPvp_item==1){
    setCursorPositionCenter(strlen("Select Map"),y,GRAY);
    gb.display.print("Select Map");

    if(NB_MAP>12){
      int maxHeight=63;
      int cur = (maxHeight-2)/((NB_MAP/4)-2);
      gb.display.setColor(GRAY);
      gb.display.fillRect(134,y+11,7,maxHeight);
      gb.display.setColor(DARKGRAY);
      gb.display.fillRect(135,y+12+cur*firstRowDisplayed,5,cur);
    }
    
    Image Maps(MAP_DATA);
    posx = 21;
    posy = y+13+(firstRowDisplayed*-1*20);
    for(int i=0;i<NB_MAP;i++){
      if(i==selectedMap){
        gb.display.setColor(PURPLE);
        gb.display.drawRect(posx-1,posy-1,28,20);
      }
      if(i/4>=firstRowDisplayed && i/4<=firstRowDisplayed+2){
        gb.display.drawImage(posx,posy,Maps,0+(i%4)*26,0+(i/4)*18,26,18);
      }
      posx=posx+28;
      if(i%4==3){
        posx=21;
        posy=posy+20;
      }
    }
  }
}

//################################################################################################################### MENU CUSTOM
void Display_MenuCustom(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(0);
  int posx = 0;
  int posy = 0;

  int y = 33;

  if(menuCustom_item==0){
    setCursorPositionCenter(strlen("CUSTOM GAME"),y,BLACK);
    gb.display.print("CUSTOM GAME");

    printPlayer(20, 40, 0, menuCustom_player);
    printPlayer(20, 57, 1, menuCustom_player);
    printPlayer(20, 74, 2, menuCustom_player);
    printPlayer(20, 91, 3, menuCustom_player);

    if(checkPlayerNumber(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==false){
      setCursorPositionCenter(strlen("Min. 2 players"),115, RED);
      gb.display.print("Min. 2 players");
    }else if(checkPlayerTypes(players[0].playerType,players[1].playerType,players[2].playerType,players[3].playerType)==false){
      setCursorPositionCenter(strlen("Min. 1 human"),115, RED);
      gb.display.print("Min. 1 human");
    }else{
      if(menuCustom_player==4){setCursorPositionCenter(strlen("Next"),115, BLACK);}
      else{setCursorPositionCenter(strlen("Next"),115, GRAY);}
      gb.display.print("Next");
      gb.display.drawRect(60,111,40,13);
    }
    
  
    if(menuCustom_detail==true){
      gb.display.setColor(WHITE);
      gb.display.fillRect(22,43,122,78);
      gb.display.setColor(BLACK);
      
      gb.display.drawRect(22,43,122,78);
      gb.display.setCursorX(26);
      gb.display.setCursorY(60);
      gb.display.print("Player type:");
      if(menuCustom_detailitem==0){gb.display.drawLine(26,66,70,66);}
      
      gb.display.setCursorX(26);
      gb.display.setCursorY(80);
      gb.display.print("Player name:  ");
      gb.display.print(players[menuCustom_player].userName);
      if(menuCustom_detailitem==1){gb.display.drawLine(26,86,70,86);}
      
      gb.display.setCursorX(54);
      gb.display.setCursorY(110);
      gb.display.print("Save and Close");
      if(menuCustom_detailitem==2){gb.display.drawLine(52,116,108,116);}
      
      if(players[menuCustom_player].playerType==0){
        printChar(90, 62, menuCustom_player);
        gb.display.setColor(BLACK);
        gb.display.setCursorX(100);
        gb.display.setCursorY(60);
        gb.display.print("Human");
      }
      
      if(players[menuCustom_player].playerType==1){
        printCpu(90, 62, menuCustom_player);
        gb.display.setColor(BLACK);
        gb.display.setCursorX(100);
        gb.display.setCursorY(60);
        gb.display.print("CPU");
      }

      if(players[menuCustom_player].playerType==2){
        printDisabled(90, 62);
        gb.display.setColor(GRAY);
        gb.display.setCursorX(100);
        gb.display.setCursorY(60);
        gb.display.print("Disabled");
      }
    }
  }

  if(menuCustom_item==1){
    setCursorPositionCenter(strlen("Select Map"),33,BLACK);
    gb.display.print("Select Map");
    
    if(NB_MAP>12){
      int maxHeight=63;
      int cur = (maxHeight-2)/((NB_MAP/4)-2);
      gb.display.setColor(GRAY);
      gb.display.fillRect(134,y+11,7,maxHeight);
      gb.display.setColor(DARKGRAY);
      gb.display.fillRect(135,y+12+cur*firstRowDisplayed,5,cur);
    }
    
    Image Maps(MAP_DATA);
    posx = 21;
    posy = y+13+(firstRowDisplayed*-1*20);
    for(int i=0;i<NB_MAP;i++){
      if(i==selectedMap){
        gb.display.setColor(RED);
        gb.display.drawRect(posx-1,posy-1,28,20);
      }
      if(i/4>=firstRowDisplayed && i/4<=firstRowDisplayed+2){
        gb.display.drawImage(posx,posy,Maps,0+(i%4)*26,0+(i/4)*18,26,18);
      }
      posx=posx+28;
      if(i%4==3){
        posx=21;
        posy=posy+20;
      }
    }
  }
}

//################################################################################################################### LOADMAP
void Display_Loadmap(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  int theme=0;
  if(menu_Item==0){theme=1;}
  if(menu_Item==1){theme=1;}
  if(menu_Item==2){theme=0;}
  display_BackgroundTheme(theme);

  Image Maps(MAP_DATA);
  gb.display.drawImage(67,90,Maps,0+(selectedMap%4)*26,0+(selectedMap/4)*18,26,18);
  //gb.display.drawImage(67,90,Maps,0+,(selectedMap*18),26,18);
}

//################################################################################################################### CREDITS
void Display_Credits(){
  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);
  
  Image Title(TITLE);
  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(1);

  int y = 32;
  setCursorPositionCenter(strlen("CREDITS"),y,BLACK);
  gb.display.print("CREDITS");

  y=y+15;
  setCursorPositionCenter(strlen("Game by"),y,BLACK);
  gb.display.print("Game by");
  
  y=y+6;
  setCursorPositionCenter(strlen("Frakasss"),y,GRAY);
  gb.display.print("Frakasss");

  y=y+13;
  setCursorPositionCenter(strlen("Maps by"),y,BLACK);
  gb.display.print("Maps by");
    
  y=y+6;
  setCursorPositionCenter(strlen("Frakasss"),y,GRAY);
  gb.display.print("Frakasss");

  y=y+13;
  setCursorPositionCenter(strlen("Tests"),y,BLACK);
  gb.display.print("Tests");

  y=y+6;
  setCursorPositionCenter(strlen("Frakasss, cris-scientist"),y,GRAY);
  gb.display.print("Frakasss, cris-scientist");

  y=y+13;
  setCursorPositionCenter(strlen("Inspiration"),y,BLACK);
  gb.display.print("Inspiration");
  
  y=y+6;
  setCursorPositionCenter(strlen("Worms, Splatoon, Snake"),y,GRAY);
  gb.display.print("Worms, Splatoon, Snake");
  
  y=y+6;
  setCursorPositionCenter(strlen("Slide 'n' Ride (by CorentinCouderc)"),y,GRAY);
  gb.display.print("Slide 'n' Ride (by CorentinCouderc)");
}



//################################################################################################################### BACKGROUND THEME
void display_BackgroundTheme(int theme){
  /*
  Image Paint001(RED_ORANGE_YELLOW);
  Image Paint002(DARK_BLUE);
  Image Paint003(JUST_BLUE);
  Image Paint004(JUST_GREEN);
  Image Paint005(JUST_RED);
  Image Paint006(JUST_PURPLE);
  Image Paint007(BLUE_PURPLE);
  Image Paint008(BLUE_GREEN_YELLOW);
  
  Image Paint010(FULL_RED);
  Image Paint011(FULL_ORANGE);
  Image Paint012(FULL_YELLOW);
  Image Paint013(FULL_GREEN);
  Image Paint014(FULL_DARKGREEN);
  Image Paint015(FULL_LIGHTBLUE);
  Image Paint016(FULL_BLUE);
  Image Paint017(FULL_DARKBLUE);
  Image Paint018(FULL_PURPLE);
  */
  if(theme==0){
    /* THEME RED ############################### */
    Image Paint010(FULL_RED);
    gb.display.drawImage(0,0,Paint010);
    
    Image Paint012(FULL_YELLOW);
    gb.display.drawImage(128,0,Paint012);
    
    Image Paint011(FULL_ORANGE);
    gb.display.drawImage(-10,90,Paint011);
  
    Image Paint018(FULL_PURPLE);
    gb.display.drawImage(140,104,Paint010);
  }

  if(theme==1){
    /* THEME BLUE ############################### */
    Image Paint016(FULL_BLUE);
    gb.display.drawImage(-6,0,Paint016);
    
    Image Paint017(FULL_DARKBLUE);
    gb.display.drawImage(129,-6,Paint017);
    
    Image Paint018(FULL_PURPLE);
    gb.display.drawImage(-16,95,Paint018);
  
    Image Paint015(FULL_LIGHTBLUE);
    gb.display.drawImage(138,96,Paint015);
  }

  if(theme==2){
    /* THEME GREEN ############################### */
    Image Paint013(FULL_GREEN);
    gb.display.drawImage(-6,0,Paint013);
    
    Image Paint018(FULL_PURPLE);
    gb.display.drawImage(129,10,Paint018);
    
    Image Paint015(FULL_LIGHTBLUE);
    gb.display.drawImage(-24,82,Paint015);
    
     Image Paint014(FULL_DARKGREEN);
    gb.display.drawImage(138,88,Paint014);
  }
}


//################################################################################################################### GAME
void Display_Game()
{
  Color color;
  Image Landscape = Image(GROUND_6X6);
  Image Buttons(BUTTONS);
  Image Player1    = Image(PLAYER1);
  Image Player2    = Image(PLAYER2);
  Image Player3    = Image(PLAYER3);
  Image Player4    = Image(PLAYER4);
  Image Paint1     = Image(PAINT1);
  Image Paint2     = Image(PAINT2);
  Image Paint3     = Image(PAINT3);
  Image Paint4     = Image(PAINT4);
  Image Cpu1       = Image(CPU1);
  Image Cpu2       = Image(CPU2);
  Image Cpu3       = Image(CPU3);
  Image Cpu4       = Image(CPU4);

  int xCenter=2;
  int yCenter=-4;
  
  for (int i=0; i<MAP_HEIGHT; i++){
    for (int j=0; j<MAP_WIDTH; j++){ 
      int tmpX = j * CHAR_WIDTH + xCenter;
      int tmpY = (i+1) * CHAR_HEIGHT + yCenter;
      
      gb.display.drawImage(tmpX,tmpY,Landscape,1*CHAR_WIDTH,0*CHAR_HEIGHT,CHAR_WIDTH,CHAR_HEIGHT);
      switch (map_layout[i][j])
      {
        case 0: /* Non walkable landscape */
          gb.display.drawImage(tmpX,tmpY,Landscape,0*CHAR_WIDTH,0*CHAR_HEIGHT,CHAR_WIDTH,CHAR_HEIGHT);
          break;
        
        case 1: /* Walkable landscape */
          /* displayed by default (see before the switch) */     
          break;

        case 2: /* Paint Player1 */
          gb.display.drawImage(tmpX,tmpY,Paint1);
          break;

        case 3: /* Paint Player2 */
          gb.display.drawImage(tmpX,tmpY,Paint2);
          break;

        case 4: /* Paint Player3 */
          gb.display.drawImage(tmpX,tmpY,Paint3);
          break;
          
        case 5: /* Paint Player4 */
          gb.display.drawImage(tmpX,tmpY,Paint4);
          break;
          
        case 6: /* Player 1*/
          if(menu_Item==0){gb.display.drawImage(tmpX,tmpY,Player1,6*(players[0].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
          if(menu_Item==1){gb.display.drawImage(tmpX,tmpY,Player1,6*(players[0].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
          if(menu_Item==2){
            if(players[0].playerType==0){gb.display.drawImage(tmpX,tmpY,Player1,6*(players[0].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
            if(players[0].playerType==1){gb.display.drawImage(tmpX,tmpY,Cpu1,6*(players[0].dir-1),6);}
          }
          break;

        case 7: /* Player 2*/
          if(menu_Item==0){gb.display.drawImage(tmpX,tmpY,Player2,6*(players[1].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
          if(menu_Item==1){gb.display.drawImage(tmpX,tmpY,Cpu2,6*(players[1].dir-1),6);}
          if(menu_Item==2){
            if(players[1].playerType==0){gb.display.drawImage(tmpX,tmpY,Player2,6*(players[1].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
            if(players[1].playerType==1){gb.display.drawImage(tmpX,tmpY,Cpu2,6*(players[1].dir-1),6);}
          }
          break;
          
        case 8: /* Player 3*/
          if(menu_Item==0){gb.display.drawImage(tmpX,tmpY,Player3,6*(players[2].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
          if(menu_Item==1){gb.display.drawImage(tmpX,tmpY,Cpu3,6*(players[2].dir-1),6);}
          if(menu_Item==2){
            if(players[2].playerType==0){gb.display.drawImage(tmpX,tmpY,Player3,6*(players[2].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
            if(players[2].playerType==1){gb.display.drawImage(tmpX,tmpY,Cpu3,6*(players[2].dir-1),6);}
          }
          break;
          
        case 9: /* Player 4*/
          if(menu_Item==0){gb.display.drawImage(tmpX,tmpY,Player4,6*(players[3].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
          if(menu_Item==1){gb.display.drawImage(tmpX,tmpY,Cpu4,6*(players[3].dir-1),6);}
          if(menu_Item==2){
            if(players[3].playerType==0){gb.display.drawImage(tmpX,tmpY,Player4,6*(players[3].dir-1),6);playerCorner(i, j, xCenter, yCenter);}
            if(players[3].playerType==1){gb.display.drawImage(tmpX,tmpY,Cpu4,6*(players[3].dir-1),6);}
          }
          break;
        
        default:
          break;
      }
    }
  }
}

//################################################################################################################### RUREADY
void Display_Ready(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(20,42,120,36);
  gb.display.setColor(DARKGRAY);
  gb.display.drawRect(22,44,116,32);

  setCursorPositionCenter(strlen(players[currentPlayer].userName+1),52,players[currentPlayer].color);
  gb.display.print(players[currentPlayer].userName);
  gb.display.print(",");

  setCursorPositionCenter(strlen("Are you ready?"),62,players[currentPlayer].color);
  gb.display.print("Are you ready?");
}


//################################################################################################################### WEAPON MENU
void Display_WeaponMenu(){
  Image weapon1   = Image(WEAPON1);
  Image weapon2   = Image(WEAPON2);
  Image weapon3   = Image(WEAPON3);
  Image weapon4   = Image(WEAPON4);
  Image give_up   = Image(GIVEUP);
  
  gb.display.setColor(BLACK);
  gb.display.fillRect(20,12,120,96);
  gb.display.setColor(DARKGRAY);
  gb.display.drawRect(22,14,116,92);

  //################################################ ICONS
  if(nbOfturn==MAX_NB_OF_TURN){
    gb.display.drawImage(26,37,weapon1);
    gb.display.drawImage(55,37,weapon2);
    gb.display.drawImage(84,37,weapon3);
    gb.display.drawImage(113,37,weapon4);
  }else{
    gb.display.drawImage(70,37,weapon1);
  }

  gb.display.drawImage(70,80,give_up);

  //################################################ Text User Color
  gb.display.setCursorX((SCREEN_WIDTH-(9*4))/2);
  gb.display.setCursorY(16);
  gb.display.setColor(players[currentPlayer].color);
  gb.display.print(players[currentPlayer].userName);

  if(menuPauseItem==0){
    if(nbOfturn==MAX_NB_OF_TURN){
      gb.display.drawRect(26+(selectedWeapon*29),37,21,21);
    }else{
      gb.display.drawRect(70,37,21,21);
    }
  }

  if(menuPauseItem==1){
    gb.display.drawRect(70,80,21,21);
  }

  //################################################ Text White
  setCursorPositionCenter(strlen("SELECT YOUR WEAPON"),24,WHITE);
  gb.display.print("SELECT YOUR WEAPON");  
  
  if(menuPauseItem==1){
    setCursorPositionCenter(strlen("Give up"),67,WHITE);
    gb.display.print("Give up");
  }
  
  if(menuPauseItem==0){
    if(selectedWeapon==0){
      setCursorPositionCenter(strlen("Step by step"),67,WHITE);
      gb.display.print("Step by step"); 
    }
    
    if(selectedWeapon==1){
      setCursorPositionCenter(strlen("Slide"),67,WHITE);
      gb.display.print("Slide"); 
    }
    
    if(selectedWeapon==2){
      setCursorPositionCenter(strlen("Explode"),67,WHITE);
      gb.display.print("Explode"); 
    }
    
    if(selectedWeapon==3){
      setCursorPositionCenter(strlen("Skip my turn"),67,WHITE);
      gb.display.print("Skip my turn"); 
    }
  }  
}

//################################################################################################################### PODIUM
void Display_Podium(){
  Image Title(TITLE);
  Image PodiumImg(PODIUM);

  int defaultY = 60;
  int adjustX = 0;

  gb.display.setColor(WHITE);
  gb.display.fillRect(0,0,160,128);

  gb.display.drawImage(43,10,Title);
  display_BackgroundTheme(1);
  
  gb.display.setFontSize(1);

  Coord podiumPlayer1;
  Coord podiumPlayer2;
  Coord podiumPlayer3;
  Coord podiumPlayer4;

  int nbOfCustoPlayer=0;
  int posPodium=40;

  //~~~~~~~~~~~~~~ Check number of player
  if(menu_Item==0){
    if(nbOfPlayer==2){adjustX=20;}
    if(nbOfPlayer==3){adjustX=10;}
  }
  if(menu_Item==1){
    if(nbOfPlayer==2){adjustX=20;}
    if(nbOfPlayer==3){adjustX=10;}
  }
  if(menu_Item==2){
    
    if(players[0].playerType!=2){nbOfCustoPlayer++;}
    if(players[1].playerType!=2){nbOfCustoPlayer++;}
    if(players[2].playerType!=2){nbOfCustoPlayer++;}
    if(players[3].playerType!=2){nbOfCustoPlayer++;}
    if(nbOfCustoPlayer==2){adjustX=20;}
    if(nbOfCustoPlayer==3){adjustX=10;}
  }

  posPodium=posPodium+adjustX;


  //~~~~~~~~~~~~~~ Display Podium
  if(menu_Item==0){
    if(nbOfPlayer==2){
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg,0,0,40,30);
    }else{
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg);
    }
  }
  if(menu_Item==1){
    if(nbOfPlayer==2){
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg,0,0,40,30);      
    }else{
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg);
    }
  }
  if(menu_Item==2){
    if(nbOfCustoPlayer==2){
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg,0,0,40,30);      
    }else{
      gb.display.drawImage(posPodium,defaultY+10,PodiumImg);
    }
  }
  


  //~~~~~~~~~~~~~~ Define Players positions
  //47-62
  if(podium.snd==0){podiumPlayer1.x=posPodium+9; podiumPlayer1.y=defaultY+12;}
  if(podium.snd==1){podiumPlayer2.x=posPodium+9; podiumPlayer2.y=defaultY+12;}
  if(podium.snd==2){podiumPlayer3.x=posPodium+9; podiumPlayer3.y=defaultY+12;}
  if(podium.snd==3){podiumPlayer4.x=posPodium+9; podiumPlayer4.y=defaultY+12;}

  //67-62
  if(podium.fst==0){podiumPlayer1.x=posPodium+29; podiumPlayer1.y=defaultY+2;}
  if(podium.fst==1){podiumPlayer2.x=posPodium+29; podiumPlayer2.y=defaultY+2;}
  if(podium.fst==2){podiumPlayer3.x=posPodium+29; podiumPlayer3.y=defaultY+2;}
  if(podium.fst==3){podiumPlayer4.x=posPodium+29; podiumPlayer4.y=defaultY+2;}

  //87-62
  if(podium.trd==0){podiumPlayer1.x=posPodium+49; podiumPlayer1.y=defaultY+22;}
  if(podium.trd==1){podiumPlayer2.x=posPodium+49; podiumPlayer2.y=defaultY+22;}
  if(podium.trd==2){podiumPlayer3.x=posPodium+49; podiumPlayer3.y=defaultY+22;}
  if(podium.trd==3){podiumPlayer4.x=posPodium+49; podiumPlayer4.y=defaultY+22;}

  //107-62
  if(podium.fth==0){podiumPlayer1.x=posPodium+69; podiumPlayer1.y=defaultY+32;}
  if(podium.fth==1){podiumPlayer2.x=posPodium+69; podiumPlayer2.y=defaultY+32;}
  if(podium.fth==2){podiumPlayer3.x=posPodium+69; podiumPlayer3.y=defaultY+32;}
  if(podium.fth==3){podiumPlayer4.x=posPodium+69; podiumPlayer4.y=defaultY+32;}



  //~~~~~~~~~~~~~~ Draw Players
  if(menu_Item==0){
    printChar(podiumPlayer1.x, podiumPlayer1.y, 0);
    printChar(podiumPlayer2.x, podiumPlayer2.y, 1);
    if(nbOfPlayer>2){printChar(podiumPlayer3.x, podiumPlayer3.y, 2);}
    if(nbOfPlayer>3){printChar(podiumPlayer4.x, podiumPlayer4.y, 3);}

    
  }

  if(menu_Item==1){
    printChar(podiumPlayer1.x, podiumPlayer1.y, 0);
    printCpu(podiumPlayer2.x, podiumPlayer2.y, 1);
    if(nbOfPlayer>2){printCpu(podiumPlayer3.x, podiumPlayer3.y, 2);}
    if(nbOfPlayer>3){printCpu(podiumPlayer4.x, podiumPlayer4.y, 3);}
  }

  if(menu_Item==2){
    if(players[0].playerType==0){printChar(podiumPlayer1.x, podiumPlayer1.y, 0);}
    if(players[0].playerType==1){printCpu (podiumPlayer1.x, podiumPlayer1.y, 0);}

    if(players[1].playerType==0){printChar(podiumPlayer2.x, podiumPlayer2.y, 1);}
    if(players[1].playerType==1){printCpu (podiumPlayer2.x, podiumPlayer2.y, 1);}

    if(players[2].playerType==0){printChar(podiumPlayer3.x, podiumPlayer3.y, 2);}
    if(players[2].playerType==1){printCpu (podiumPlayer3.x, podiumPlayer3.y, 2);}

    if(players[3].playerType==0){printChar(podiumPlayer4.x, podiumPlayer4.y, 3);}
    if(players[3].playerType==1){printCpu (podiumPlayer4.x, podiumPlayer4.y, 3);}
  }


  //~~~~~~~~~~~~~~ Draw Scores
  //48
  gb.display.setCursorX(posPodium+10-((intLength(players[podium.snd].score)*4)/2));  gb.display.setCursorY(defaultY+42); gb.display.setColor(BLACK);
  gb.display.print(players[podium.snd].score);

  //68
  gb.display.setCursorX(posPodium+10+20-((intLength(players[podium.snd].score)*4)/2));  gb.display.setCursorY(defaultY+42);  gb.display.setColor(BLACK);
  gb.display.print(players[podium.fst].score);

  //88
  gb.display.setCursorX(posPodium+10+40-((intLength(players[podium.snd].score)*4)/2));  gb.display.setCursorY(defaultY+42);  gb.display.setColor(BLACK);
  if(menu_Item==0){
    if(nbOfPlayer>2){gb.display.print(players[podium.trd].score);}
  }
  if(menu_Item==1){
    if(nbOfPlayer>2){gb.display.print(players[podium.trd].score);}
  }
  if(menu_Item==2){
    if(nbOfCustoPlayer>2){gb.display.print(players[podium.trd].score);}
  }

  //108
  gb.display.setCursorX(posPodium+10+60-((intLength(players[podium.snd].score)*4)/2));  gb.display.setCursorY(defaultY+42);  gb.display.setColor(BLACK);
  if(menu_Item==0){
    if(nbOfPlayer>3){gb.display.print(players[podium.fth].score);}
  }
  if(menu_Item==1){
    if(nbOfPlayer>3){gb.display.print(players[podium.fth].score);}
  }
  if(menu_Item==2){
    if(nbOfCustoPlayer>3){gb.display.print(players[podium.fth].score);}
  }



  setCursorPositionCenter(strlen("CONGRATULATION"),defaultY-21, BLACK);
  gb.display.print("CONGRATULATION"); 
  setCursorPositionCenter(strlen(players[podium.fst].userName)+2,defaultY-13, BLACK);
  gb.display.print(players[podium.fst].userName);
  gb.display.print("!!"); 
}

//################################################################################################################### GAME TEXT
void Display_TextPlay(){
  if(menuPauseItem==0){
    gb.display.setCursorY(111);
    gb.display.setCursorX(23);
    gb.display.setColor(players[currentPlayer].color);
    gb.display.print(players[currentPlayer].userName);
    gb.display.print(" is playing...");
  }
}

//################################################################################################################### SELECTED WEAPON
void Display_SelectedWeapon(){
  if(menuPauseItem==0){
    Image Wp1        = Image(WEAPON1);
    Image Wp2        = Image(WEAPON2);
    Image Wp3        = Image(WEAPON3);
    Image Wp4        = Image(WEAPON4);
    
    if(selectedWeapon==0){gb.display.drawImage(0,SCREEN_HEIGHT-21,Wp1);}
    if(selectedWeapon==1){gb.display.drawImage(0,SCREEN_HEIGHT-21,Wp2);}
    if(selectedWeapon==2){gb.display.drawImage(0,SCREEN_HEIGHT-21,Wp3);}
    if(selectedWeapon==3){gb.display.drawImage(0,SCREEN_HEIGHT-21,Wp4);}
    gb.display.setColor(players[currentPlayer].color);
    gb.display.drawRect(0,SCREEN_HEIGHT-21,21,21);
    
    if(menuPauseItem==0){
      if(players[currentPlayer].weapon==0){
        gb.display.setCursorX(2);
        gb.display.setCursorY(121);
        gb.display.printf("%d",nbOfturn);
      }
    }
  }else{
    /*Menu:Weapon B: GiveUp!*/
    gb.display.setColor(BLACK);
    gb.display.fillRect(20,28,120,54);
    gb.display.setColor(DARKGRAY);
    gb.display.drawRect(22,30,116,50);
  
    setCursorPositionCenter(strlen("Give up"),34,WHITE);
    gb.display.print("Give up");

    setCursorPositionCenter(strlen("and go back to main menu?"),41,GRAY);
    gb.display.print("and go back to main menu?");
    
    Image GUp = Image(GIVEUP);
    gb.display.drawImage(70,48,GUp);
  }
}

//################################################################################################################### CPU
void Display_CPU(){
  gb.display.setColor(players[currentPlayer].color);
  gb.display.drawRect(0,SCREEN_HEIGHT-21,21,21);
  gb.display.setColor(WHITE);
  gb.display.fillRect(1,SCREEN_HEIGHT-20,19,19);
  printCpu(10,SCREEN_HEIGHT-11, currentPlayer);
  
  gb.display.setCursorY(120);
  gb.display.setCursorX(23);
  gb.display.setColor(GRAY);
  gb.display.print("Processing...");
}


//################################################################################################################### BUTTONS
void Display_Buttons(){
  Image Buttons(BUTTONS);
  Image BtnMenu(BUTTONMENU);
  
  
  switch (GetGameState())
  {
    case GAMEMAKERS: 
      gb.display.drawImage(152,120,Buttons,7,0,7,7); /* A */
      break;
      
    case TITLESCREEN: 
      gb.display.drawImage(152,120,Buttons,7,0,7,7); /* A */
      break;    
      
    case MENU:
      //gb.display.drawImage(20,120,Buttons,0,0,7,7);   /* Arrow */
      gb.display.drawImage(115,120,Buttons,7,0,7,7); /* A */
      gb.display.setColor(BLACK);
      //gb.display.setCursor(29, 121);
      //gb.display.print("Select");
      gb.display.setCursorX(124);
      gb.display.setCursorY(121);
      gb.display.print("Next");
      break;

    case MENU_PVP:
      gb.display.drawImage(20,120,Buttons,14,0,7,7); /* B */
      gb.display.drawImage(115,120,Buttons,7,0,7,7); /* A */
      gb.display.setColor(BLACK);
      gb.display.setCursorX(29);
      gb.display.setCursorY(121);
      gb.display.print("Back");
      gb.display.setCursorX(124);
      gb.display.setCursorY(121);
      gb.display.print("Next");
      break;

    case MENU_PVE:
      gb.display.drawImage(20,120,Buttons,14,0,7,7); /* B */
      gb.display.drawImage(115,120,Buttons,7,0,7,7); /* A */
      gb.display.setColor(BLACK);
      gb.display.setCursorX(29);
      gb.display.setCursorY(121);
      gb.display.print("Back");
      gb.display.setCursorX(124);
      gb.display.setCursorY(121);
      gb.display.print("Next");      
      break;

    case MENU_CUSTOM:
      if(menuCustom_detail==false){
        gb.display.drawImage(1,120,Buttons,14,0,7,7); /* B */
        gb.display.setColor(BLACK);
        gb.display.setCursorX(10);
        gb.display.setCursorY(121);
        gb.display.print("Back");

        gb.display.setColor(BLACK);
        gb.display.setCursorX(135);//124
        gb.display.setCursorY(121);
        gb.display.print("Select");
        gb.display.drawImage(126,120,Buttons,7,0,7,7); /* A */        
      }
      
      if(menuCustom_detail==true){
        if(menuCustom_detailitem==0){gb.display.drawImage(134,60, Buttons,0,0,7,7);  /* + */}
        if(menuCustom_detailitem==1){gb.display.drawImage(134,80, Buttons,7,0,7,7); /* A */}
        if(menuCustom_detailitem==2){gb.display.drawImage(134,110,Buttons,7,0,7,7); /* A */}
      }
      break;
      
    case CREDITS: 
      gb.display.drawImage(152,120,Buttons,14,0,7,7); /* B */
      break;  
      
    case RUREADY: 
      gb.display.drawImage(129,67,Buttons,7,0,7,7); /* A */
      break;
     
    case PLAY:
      if(menuPauseItem==0){
        if(selectedWeapon==0){
          /*Menu:Weapon Croix: Move */
          gb.display.drawImage(138,111,BtnMenu);
          gb.display.drawImage(23,119, Buttons,0,0,7,7);
          
          gb.display.setColor(GRAY);
          gb.display.setCursorY(120);
          
          gb.display.setCursorX(134);
          gb.display.print("Weapon");
          
          gb.display.setCursorX(33);
          gb.display.print("Move");
        }
        if(selectedWeapon==1){
          /*Menu:Weapon Croix: Move */
          gb.display.drawImage(137,111,BtnMenu);
          gb.display.drawImage(23,119, Buttons,0,0,7,7);
          
          gb.display.setColor(GRAY);
          gb.display.setCursorY(120);
          
          gb.display.setCursorX(134);
          gb.display.print("Weapon");
          
          gb.display.setCursorX(33);
          gb.display.print("Move");
        }
        if(selectedWeapon==2){
          /*Menu:Weapon B: Kaboom*/
          gb.display.drawImage(137,111,BtnMenu);
          gb.display.drawImage(23,119, Buttons,14,0,7,7); /* B */
          
          gb.display.setColor(GRAY);
          gb.display.setCursorY(120);
          
          gb.display.setCursorX(134);
          gb.display.print("Weapon");
          
          gb.display.setCursorX(33);
          gb.display.print("Kaboom!");
        }
        if(selectedWeapon==3){
          /*Menu:Weapon B: Next player!*/
          gb.display.drawImage(137,111,BtnMenu);
          gb.display.drawImage(23,119, Buttons,14,0,7,7); /* B */
          
          gb.display.setColor(GRAY);
          gb.display.setCursorY(120);
          
          gb.display.setCursorX(134);
          gb.display.print("Weapon");
          
          gb.display.setCursorX(33);
          gb.display.print("Next player!");
        }
      }else{
        gb.display.drawImage(106,71,BtnMenu);
        gb.display.drawImage(24,71, Buttons,14,0,7,7); /* B */
        
        gb.display.setCursorY(72);
        
        gb.display.setCursorX(126);
        gb.display.setColor(GRAY);
        gb.display.print("No!");
        
        gb.display.setCursorX(33);
        gb.display.setColor(GRAY);
        gb.display.print("Yes!");
      }
      break;

    case WIN:
      gb.display.drawImage(2,119, Buttons,7,0,7,7); /* A */
      gb.display.drawImage(101, 119, Buttons,14,0,7,7); /* B */

      gb.display.setCursorY(120);
      
      gb.display.setCursorX(10);
      gb.display.setColor(BLACK);
      gb.display.print("See Map");
      
      gb.display.setCursorX(110);
      gb.display.setColor(BLACK);
      gb.display.print("Back to Menu");
      break;

    case SEEMAP:
      gb.display.drawImage(120,112, Buttons,14,0,7,7); /* B */
      gb.display.setCursorY(113); gb.display.setCursorX(130); gb.display.setColor(GRAY);
      gb.display.print("Back to");
      gb.display.setCursorY(120); gb.display.setCursorX(130); gb.display.setColor(GRAY);
      gb.display.print("Podium");
      
      break;
  }
}

//################################################################################################################### CONGRATS
void Display_Congrats(){
  gb.display.setCursorY(113);
  gb.display.setCursorX(2);
  gb.display.setColor(WHITE);
  gb.display.print("CONGRATULATION");
  gb.display.setCursorY(121);
  gb.display.setCursorX(14);
  gb.display.setColor(players[podium.fst].color);
  gb.display.print(players[podium.fst].userName);
  gb.display.print("!!"); 

  if(podium.fst==0){
    Image Player1    = Image(PLAYER1);
    Image Cpu1       = Image(CPU1);
    if(menu_Item==0){gb.display.drawImage(5,120,Player1);playerCornerPodium(5,120);}
    if(menu_Item==1){gb.display.drawImage(5,120,Player1);playerCornerPodium(5,120);}
    if(menu_Item==2){if(players[podium.fst].playerType==0){gb.display.drawImage(5,120,Player1);playerCornerPodium(5,120);}
                     if(players[podium.fst].playerType==1){gb.display.drawImage(5,120,Cpu1);cpuCornerPodium(5,120);}}
  }

  if(podium.fst==1){
    Image Player2    = Image(PLAYER2);
    Image Cpu2       = Image(CPU2);
    if(menu_Item==0){gb.display.drawImage(5,120,Player2);playerCornerPodium(5,120);}
    if(menu_Item==1){gb.display.drawImage(5,120,Cpu2);cpuCornerPodium(5,120);}
    if(menu_Item==2){if(players[podium.fst].playerType==0){gb.display.drawImage(5,120,Player2);playerCornerPodium(5,120);}
                     if(players[podium.fst].playerType==1){gb.display.drawImage(5,120,Cpu2);cpuCornerPodium(5,120);}}
  }

  if(podium.fst==2){
    Image Player3    = Image(PLAYER3);
    Image Cpu3       = Image(CPU3);
    if(menu_Item==0){gb.display.drawImage(5,120,Player3);playerCornerPodium(5,120);}
    if(menu_Item==1){gb.display.drawImage(5,120,Cpu3);cpuCornerPodium(5,120);}
    if(menu_Item==2){if(players[podium.fst].playerType==0){gb.display.drawImage(5,120,Player3);playerCornerPodium(5,120);}
                     if(players[podium.fst].playerType==1){gb.display.drawImage(5,120,Cpu3);cpuCornerPodium(5,120);}}
  }

  if(podium.fst==3){
    Image Player4    = Image(PLAYER4);
    Image Cpu4       = Image(CPU4);
    if(menu_Item==0){gb.display.drawImage(5,120,Player4);playerCornerPodium(5,120);}
    if(menu_Item==1){gb.display.drawImage(5,120,Cpu4);cpuCornerPodium(5,120);}
    if(menu_Item==2){if(players[podium.fst].playerType==0){gb.display.drawImage(5,120,Player4);playerCornerPodium(5,120);}
                     if(players[podium.fst].playerType==1){gb.display.drawImage(5,120,Cpu4);cpuCornerPodium(5,120);}}
  }
}


//################################################################################################################### CUSTOM PLAYER
void printPlayer1(int posx,int posy, int userId, int menuCustom_player){
  
  if(userId==menuCustom_player){
    Image ButtonMenu(BUTTONMENU);
    
    gb.display.drawImage(posx+83,posy+6,ButtonMenu); 
    gb.display.setColor(BLACK);
    gb.display.setCursorX(posx+102);
    gb.display.setCursorY(posy+7);
    gb.display.print("Edit");
  }else{
    gb.display.setColor(GRAY);
  }
  
  gb.display.drawRect(posx,posy,120,18);

  if(players[userId].playerType==0){
    printChar(posx+4+5, posy+4+5, userId);
    if(userId==menuCustom_player){ gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+6);
    gb.display.print(players[userId].userName);
  }
  
  if(players[userId].playerType==1){
    printCpu(posx+4+5, posy+4+5, userId);
    if(userId==menuCustom_player){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+6);
    gb.display.print(players[userId].userName);
  }

  if(players[userId].playerType==2){
    printDisabled(posx+4+5, posy+4+5);
    if(userId==menuCustom_player){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+6);
    gb.display.print("Disabled");
  }
}

//################################################################################################################### CUSTOM PLAYER
void printPlayer(int posx,int posy, int userId, int menuCustom_player){
  
  if(userId==menuCustom_player){
    Image Buttons(BUTTONS);

    gb.display.drawImage(posx+93,posy+4, Buttons,7,0,7,7);
    gb.display.setColor(BLACK);
    gb.display.setCursorX(posx+102);
    gb.display.setCursorY(posy+5);
    gb.display.print("Edit");
  }else{
    gb.display.setColor(GRAY);
  }
  
  gb.display.drawRect(posx,posy,120,15);

  if(players[userId].playerType==0){
    printChar(posx+4+5, posy+4+3, userId);
    if(userId==menuCustom_player){ gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+5);
    gb.display.print(players[userId].userName);
  }
  
  if(players[userId].playerType==1){
    printCpu(posx+4+5, posy+4+3, userId);
    if(userId==menuCustom_player){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+5);
    gb.display.print(players[userId].userName);
  }

  if(players[userId].playerType==2){
    printDisabled(posx+4+5, posy+4+3);
    if(userId==menuCustom_player){gb.display.setColor(BLACK);}
    else{gb.display.setColor(GRAY);}
    gb.display.setCursorX(posx+25);
    gb.display.setCursorY(posy+5);
    gb.display.print("Disabled");
  }
}


//################################################################################################################### FUNCTIONS
void printChar(int posx, int posy, int userId){
  gb.display.setColor(players[userId].color);
  gb.display.fillCircle(posx,posy,5);
  
  gb.display.setColor(BLACK);
  gb.display.fillRect(posx-2,posy-2,2,3);
  gb.display.fillRect(posx+2,posy-2,2,3);
  gb.display.setColor(WHITE);
  gb.display.fillRect(posx-1,posy+2,4,2);
  gb.display.drawPixel(posx-2,posy+2);
}

//################################################################################################################### FUNCTIONS
void printDisabled(int posx,int posy){
  gb.display.setColor(GRAY);
  gb.display.fillCircle(posx,posy,5);
  gb.display.setColor(WHITE);
  gb.display.fillCircle(posx,posy,3);
  gb.display.setColor(GRAY);
  gb.display.drawLine(posx-3,posy-3,posx+3,posy+3);
}

//################################################################################################################### FUNCTIONS
void printCpu(int posx, int posy, int userId){
  gb.display.setColor(DARKGRAY);
  gb.display.fillRect(posx-6,posy-4,3,9);  
  gb.display.setColor(GRAY);
  gb.display.fillRect(posx-3,posy-4,10,9);
  gb.display.drawLine(posx-5,posy-4,posx-6,posy-1);   
  gb.display.setColor(BLACK);
  gb.display.drawPixel(posx-5,posy-5);
  gb.display.drawPixel(posx+5,posy-5);
  gb.display.drawPixel(posx-6,posy-6);
  gb.display.drawPixel(posx+4,posy-6);
  gb.display.setColor(WHITE);
  gb.display.fillRect(posx-1,posy+2,6,2);
  
  gb.display.setColor(players[userId].color);
  gb.display.fillRect(posx-1,posy-2,2,3);
  gb.display.fillRect(posx+3,posy-2,2,3);
}

//################################################################################################################### FUNCTIONS
void printName(int posx, int posy, int userId){
  gb.display.setCursorX((posx-(strlen(players[userId].userName)*4)/2));
  gb.display.setCursorY(posy+10);
  gb.display.setColor(BLACK);
  gb.display.print(players[userId].userName);
}

//################################################################################################################### FUNCTIONS
void setCursorPositionCenter(int txtLength,int y, Color txtColor){
  gb.display.setColor(txtColor);
  gb.display.setCursorX((SCREEN_WIDTH-(txtLength*4))/2);
  gb.display.setCursorY(y);
}

//################################################################################################################### FUNCTIONS
void setCursorPositionCenter(int txtLength,int x, int y, Color txtColor){
  gb.display.setColor(txtColor);
  gb.display.setCursorX((x-(txtLength*4))/2);
  gb.display.setCursorY(y);
}


//################################################################################################################### FUNCTIONS
void playerCorner(int tmpY, int tmpX, int xCenter, int yCenter){
  int x = tmpX * CHAR_WIDTH + xCenter;
  int y = (tmpY+1) * CHAR_HEIGHT + yCenter;
  gb.display.setColor(WHITE);
  if(PosValue(tmpX-1,tmpY)==1 && PosValue(tmpX-1,tmpY-1)==1 && PosValue(tmpX,tmpY-1)==1)  {gb.display.drawPixel(x,y);}
  if(PosValue(tmpX,tmpY-1)==1 && PosValue(tmpX+1,tmpY-1)==1 && PosValue(tmpX+1,tmpY)==1)  {gb.display.drawPixel(x+5,y);}
  if(PosValue(tmpX-1,tmpY)==1 && PosValue(tmpX-1,tmpY+1)==1 && PosValue(tmpX,tmpY+1)==1)  {gb.display.drawPixel(x,y+5);}
  if(PosValue(tmpX,tmpY+1)==1 && PosValue(tmpX+1,tmpY+1)==1 && PosValue(tmpX+1,tmpY)==1)  {gb.display.drawPixel(x+5,y+5);}
}

//################################################################################################################### FUNCTIONS
void playerCornerPodium(int x, int y){
  gb.display.setColor(BLACK);
  gb.display.drawPixel(x,y);
  gb.display.drawPixel(x+5,y);
  gb.display.drawPixel(x,y+5);
  gb.display.drawPixel(x+5,y+5);
}

//################################################################################################################### FUNCTIONS
void cpuCornerPodium(int x, int y){
  gb.display.setColor(BLACK);
  gb.display.drawPixel(x,y);
  gb.display.drawPixel(x+1,y);
  gb.display.drawPixel(x+4,y);
  gb.display.drawPixel(x+5,y);
}


void Display_Debug(){
  gb.display.setCursorX(0);
  //gb.display.setCursorY(110);
  gb.display.setCursorY(0);
  gb.display.setColor(WHITE);
}
