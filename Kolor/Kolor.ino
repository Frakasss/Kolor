#include <Gamebuino-Meta.h>

#include "Define.h"

#include "Maps.h"
#include "Utils.h"

#include "Palettes.h"
#include "Sprites_8x8.h"
#include "Sprites_6x6.h"
#include "Wallpaper.h"




bool isWin = false;
bool isLost = false;
int previousWalkedState = 1;

int menuItem = 0;
int nbOfPlayer = 4;
int nbOfCPU = 0;
int currentMap = 0;

int currentPlayer = 0;
int anim=0;
PlayerState players[4];
Podium podium;


GameState currentGameState = MENU;
void SetGameState(GameState newState){
  currentGameState = newState;
}

GameState GetGameState(){
  return currentGameState;
}

void NextPlayer(){
  anim=0;
  currentPlayer++;
  if(currentPlayer==nbOfPlayer){currentPlayer=0;}
  SetGameState(RUREADY);
}

void setup() 
{
  gb.begin();
  gb.display.setPalette(PALETTE);
  InitMap(currentMap);
  InitPlayerPosition();
}

void InitPlayerPosition()
{
  for(int i = 0; i<nbOfPlayer; i++){
    players[i].x       = map_settings[i][0];
    players[i].y       = map_settings[i][1];
    players[i].cptAnim = 0;
    players[i].state   = 0;
    players[i].dir     = map_settings[i][2];
    players[i].score   = 0;
    map_layout[players[i].y][players[i].x] = 6+i;
  }
}

void Reset(){
  menuItem = 0;
  nbOfPlayer = 4;
  nbOfCPU = 0;
  currentMap = 0;
  
  InitMap(currentMap);
  InitPlayerPosition();
  isWin = false;
  isLost = false;
  currentPlayer=0;

  podium.fst=0;
  podium.snd=0;
  podium.trd=0;
  podium.fth=0;
}


//############################################################################################# LOOP
void loop() 
{
  while(!gb.update());
  gb.display.clear();

  switch (GetGameState())
  {
    case IDLE:
      break;

    case GAMEMAKERS:
      ReadPlayerInput_Creator();
      Display_Creator();
      break;

    case TITLESCREEN:
      Reset();
      ReadPlayerInput_Intro();
      Display_Titlescreen();
      break;

    case MENU:
      ReadPlayerInput_Menu();
      Display_Menu();
      break;
    
    case RUREADY: 
      ReadPlayerInput_Ready();
      Display_Game();
      Display_TextReady();
      Gameplay_CheckWin();
      break;
      
    case PLAY: 
      ReadPlayerInput_Game();
      Display_Game();
      Display_TextPlay();
      break;
      
    case MOVE_UP: 
    case MOVE_DOWN:
    case MOVE_LEFT:
    case MOVE_RIGHT: 
      Gameplay_UpdatePosition();
      ReadPlayerInput_Game2();
      Display_Game();
      Display_TextPlay();
      break;
      
    case EXPLOSE: 
      Gameplay_Explosion();
      Display_Game();
      Display_TextPlay();
      break;
      
    case WIN:
      Display_Podium();
      //ReadPlayerInput_Win();
      break;
      
    default: 
      break;
  }
}




//############################################################################################# PLAYER INPUT
void ReadPlayerInput()
{
  if (gb.buttons.pressed(BUTTON_MENU)){
    Reset();
  }
}


void ReadPlayerInput_Creator(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(TITLESCREEN);
  }
  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(TITLESCREEN);
  }
}


void ReadPlayerInput_Intro(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(MENU);
  }
  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(GAMEMAKERS);
  }
}


void ReadPlayerInput_Menu(){
  if(gb.buttons.pressed(BUTTON_DOWN)){
    menuItem++;
    if(menuItem==1){menuItem=2;}
    if(menuItem>3){menuItem=3;}
  }

  if(gb.buttons.pressed(BUTTON_UP)){
    menuItem--;
    if(menuItem==1){menuItem=0;} //skip CPU
    if(menuItem<0){menuItem=0;}
  }

  if(gb.buttons.pressed(BUTTON_LEFT)){
    switch(menuItem){
      case 0: 
        nbOfPlayer--;
        if(nbOfPlayer<2){nbOfPlayer=2;}
        if(nbOfCPU==nbOfPlayer){nbOfCPU--;}
        break;
        
      case 1: 
        nbOfCPU--;
        if(nbOfCPU<0){nbOfCPU=0;}
        break;
        
      case 2: 
        currentMap--;
        if(currentMap<0){currentMap=0;}
        InitMap(currentMap);
        InitPlayerPosition();
        break;
        
      default:break;
    }
  }

  if(gb.buttons.pressed(BUTTON_RIGHT)){
    switch(menuItem){
      case 0: 
        nbOfPlayer++;
        if(nbOfPlayer>4){nbOfPlayer=4;}
        break;
        
      case 1: 
        nbOfCPU++;
        if(nbOfCPU==nbOfPlayer){nbOfCPU--;}
        break;
        
      case 2: 
        currentMap++;
        if(currentMap>NB_MAP-1){currentMap=NB_MAP-1;}
        InitMap(currentMap);
        InitPlayerPosition();
        break;
        
      default:break;
    }
  }

  if(gb.buttons.pressed(BUTTON_A)){
    InitMap(currentMap);
    InitPlayerPosition();
    SetGameState(RUREADY);
  }

  if(gb.buttons.pressed(BUTTON_B)){
    SetGameState(TITLESCREEN);
  }

}


void ReadPlayerInput_Ready(){
  if(gb.buttons.pressed(BUTTON_A)){
    SetGameState(PLAY);
  }
}

void ReadPlayerInput_Game(){
  if (gb.buttons.pressed(BUTTON_UP)){
    SetGameState(MOVE_UP);
  }
  else if (gb.buttons.pressed(BUTTON_DOWN)){
    SetGameState(MOVE_DOWN);
  }
  else if (gb.buttons.pressed(BUTTON_LEFT)){
    SetGameState(MOVE_LEFT);
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT)){
    SetGameState(MOVE_RIGHT);
  }
  else if (gb.buttons.pressed(BUTTON_B)){
    SetGameState(EXPLOSE);
  }
}

void ReadPlayerInput_Game2(){
  if(gb.buttons.pressed(BUTTON_B)){
    if(GetGameState()!=RUREADY){
      SetGameState(EXPLOSE);
    }
  }
}












//################################################################################################################### GAMEPLAY
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
        NextPlayer();
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

void Gameplay_Explosion(){
  int y = players[currentPlayer].y;
  int x = players[currentPlayer].x;

  if(anim==0){
    if(canPaint(y-1, x-1)){map_layout[y-1][x-1] = currentPlayer+2;}
    if(canPaint(y-1, x  )){map_layout[y-1][x  ] = currentPlayer+2;}
    if(canPaint(y-1, x+1)){map_layout[y-1][x+1] = currentPlayer+2;}
    
    if(canPaint(y  , x-1)){map_layout[y  ][x-1] = currentPlayer+2;}
    if(canPaint(y  , x+1)){map_layout[y  ][x+1] = currentPlayer+2;}

    if(canPaint(y+1, x-1)){map_layout[y+1][x-1] = currentPlayer+2;}
    if(canPaint(y+1, x  )){map_layout[y+1][x  ] = currentPlayer+2;}
    if(canPaint(y+1, x+1)){map_layout[y+1][x+1] = currentPlayer+2;} 

    anim=1;
  }else{
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

     NextPlayer();       
  }
}


void Gameplay_CheckWin(){
  int nbOfWhitePixel = 0;
  players[0].score=0;
  players[1].score=0;
  players[2].score=0;
  players[3].score=0;
  
  for (int i=0; i<MAP_HEIGHT; i++){
    for (int j=0; j<MAP_WIDTH; j++){ 
      switch(map_layout[i][j]){
        case 1: nbOfWhitePixel++; break;
        case 2: players[0].score++; break;
        case 3: players[1].score++; break;
        case 4: players[2].score++; break;
        case 5: players[3].score++; break;
        default: break;
      }
    }
  }



  //1st
  if(players[0].score>players[1].score && players[0].score>players[2].score && players[0].score>players[3].score){ podium.fst=0;}
  if(players[1].score>players[0].score && players[1].score>players[2].score && players[1].score>players[3].score){ podium.fst=1;}
  if(players[2].score>players[1].score && players[2].score>players[0].score && players[2].score>players[3].score){ podium.fst=2;}
  if(players[3].score>players[1].score && players[3].score>players[2].score && players[3].score>players[0].score){ podium.fst=3;}

  //4th
  if(players[0].score<players[1].score && players[0].score<players[2].score && players[0].score<players[3].score){ podium.fth=0;}
  if(players[1].score<players[0].score && players[1].score<players[2].score && players[1].score<players[3].score){ podium.fth=1;}
  if(players[2].score<players[1].score && players[2].score<players[0].score && players[2].score<players[3].score){ podium.fth=2;}
  if(players[3].score<players[1].score && players[3].score<players[2].score && players[3].score<players[0].score){ podium.fth=3;}

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
}

//################################################################################################################### DISPLAY
void Display_Game()
{
  Color color;
  Image Landscape = Image(GROUND_6X6);
  Image Paint_1   = Image(PAINT_1_6X6);
  Image Paint_2   = Image(PAINT_2_6X6);
  Image Paint_3   = Image(PAINT_3_6X6);
  Image Paint_4   = Image(PAINT_4_6X6);
  
  Image Player    = Image(PLAYERS);

  int xCenter=2;
  int yCenter=-1;
  
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
          gb.display.drawImage(tmpX,tmpY,Paint_1);
          break;

        case 3: /* Paint Player2 */
          gb.display.drawImage(tmpX,tmpY,Paint_2);
          break;

        case 4: /* Paint Player3 */
          gb.display.drawImage(tmpX,tmpY,Paint_3);
          break;
          
        case 5: /* Paint Player4 */
          gb.display.drawImage(tmpX,tmpY,Paint_4);
          break;
          
        case 6: /* Player 1*/
          gb.display.drawImage(tmpX,tmpY,Player,0,0,6,6);
          //gb.display.drawImage(tmpX-2,tmpY-2,Player,0,0,8,8);
          //gb.display.drawImage(tmpX,tmpY,Player_1,1*(CHAR_WIDTH-1),0*(CHAR_HEIGHT-1),CHAR_WIDTH-1,CHAR_HEIGHT-1);
          break;

        case 7: /* Player 2*/
          gb.display.drawImage(tmpX,tmpY,Player,6,0,6,6);
          //gb.display.drawImage(tmpX-2,tmpY-2,Player,8,0,8,8);
          //gb.display.drawImage(tmpX,tmpY,Player_2,1*(CHAR_WIDTH-1),0*(CHAR_HEIGHT-1),CHAR_WIDTH-1,CHAR_HEIGHT-1);
          break;
          
        case 8: /* Player 3*/
          gb.display.drawImage(tmpX,tmpY,Player,12,0,6,6);
          //gb.display.drawImage(tmpX-2,tmpY-2,Player,16,0,8,8);
          //gb.display.drawImage(tmpX,tmpY,Player_3,1*(CHAR_WIDTH-1),0*(CHAR_HEIGHT-1),CHAR_WIDTH-1,CHAR_HEIGHT-1);
          break;
          
        case 9: /* Player 4*/
          gb.display.drawImage(tmpX,tmpY,Player,18,0,6,6);
          //gb.display.drawImage(tmpX-2,tmpY-2,Player,24,0,8,8);
          //gb.display.drawImage(tmpX,tmpY,Player_4,1*(CHAR_WIDTH-1),0*(CHAR_HEIGHT-1),CHAR_WIDTH-1,CHAR_HEIGHT-1);
          break;
        
        default:
          break;
      }
    }
  }
}

void Display_Creator(){
  Image GameMakers(GamemakersData);
  gb.display.drawImage(0,0,GameMakers,160,128); 
}

void Display_Titlescreen(){
  Image Titlescreen(GAMETITLE);
  gb.display.drawImage(0,0,Titlescreen); 
}

void Display_Menu(){
  Image MenuBkg(MENUBKG);
  Image PointerLeft(POINTERLEFT);
  Image PointerRight(POINTERRIGHT);
  int pointerXposLeft=55;
  int pointerXposRight=102;
  int itemYpos = 0;
  gb.display.drawImage(0,0,MenuBkg); 
 
  gb.display.setFontSize(1);
  gb.display.setColor(BLACK);

  //########## Item 0
  itemYpos=42;
  gb.display.setCursorX(60);
  gb.display.setCursorY(itemYpos);
  gb.display.printf("Players: %d", nbOfPlayer);
  if(menuItem==0){
    if(nbOfPlayer==2){
      gb.display.drawImage(pointerXposLeft, itemYpos, PointerLeft,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposLeft, itemYpos, PointerLeft,0,0,3,6);}
    
    if(nbOfPlayer==4){
      gb.display.drawImage(pointerXposRight,itemYpos, PointerRight,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposRight,itemYpos, PointerRight,0,0,3,6);}
  }
/*
  //########## Item 1
  itemYpos = 53;
  gb.display.setCursorX(70);
  gb.display.setCursorY(itemYpos);
  gb.display.printf("CPU: %d", nbOfCPU); 
  if(menuItem==1){
    if(nbOfCPU==0){
      gb.display.drawImage(pointerXposLeft, itemYpos,PointerLeft,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposLeft, itemYpos,PointerLeft,0,0,3,6);}
    
    if(nbOfCPU==nbOfPlayer-1){
      gb.display.drawImage(pointerXposRight,itemYpos,PointerRight,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposRight,itemYpos,PointerRight,0,0,3,6);}
  }
*/
  //########## Item 2
  itemYpos = 63;
  gb.display.setCursorX(75);
  gb.display.setCursorY(itemYpos);
  gb.display.printf("Map:");
  if(menuItem==2){
    if(currentMap==0){
      gb.display.drawImage(pointerXposLeft, itemYpos+12,PointerLeft,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposLeft, itemYpos+12,PointerLeft,0,0,3,6);}
    
    if(currentMap==NB_MAP-1){
      gb.display.drawImage(pointerXposRight,itemYpos+12,PointerRight,3,0,3,6);}
    else{
      gb.display.drawImage(pointerXposRight,itemYpos+12,PointerRight,0,0,3,6);}
  }


  int mapBorderX = (SCREEN_WIDTH-MAP_WIDTH)/2;
  int mapBorderY = 72;

  for (int i=0; i<MAP_HEIGHT; i++){
    for (int j=0; j<MAP_WIDTH; j++){ 
      if(map_layout[i][j]==0){
        gb.display.drawPixel(mapBorderX+j,mapBorderY+i);
      }
    }
  }

  //########## Item 3
  itemYpos = 100;
  gb.display.setCursorX(75);
  gb.display.setCursorY(itemYpos);
  gb.display.printf("Go!");
  if(menuItem==3){
    gb.display.drawImage(pointerXposLeft, itemYpos,PointerRight,0,0,3,6);
    gb.display.drawImage(pointerXposRight,itemYpos,PointerLeft,0,0,3,6);
  }




  //########## Debug
  /*
  itemYpos = 108;
  gb.display.setCursorX(10);
  gb.display.setCursorY(itemYpos);
  gb.display.printf("Debug: %d", 0);
  */
}

void Display_Podium(){
  Image MenuBkg(MENUBKG);
  Image PodiumImg(PODIUM);
  Image Player(PLAYERS);
  gb.display.setFontSize(1);
  gb.display.setColor(BLACK);
  
  gb.display.drawImage(0,0,MenuBkg);
  gb.display.drawImage(40,60,PodiumImg);
  gb.display.drawImage(47, 62,  Player,podium.snd*6,0,6,6);//2nd
  gb.display.drawImage(67, 52,  Player,podium.fst*6,0,6,6);//1st
  gb.display.drawImage(87, 72,  Player,podium.trd*6,0,6,6);//3rd
  gb.display.drawImage(107,82,  Player,podium.fth*6,0,6,6);//4th

  gb.display.setCursorX(45);
  gb.display.setCursorY(92);
  gb.display.printf("%d",players[podium.snd].score);

  gb.display.setCursorX(65);
  gb.display.printf("%d",players[podium.fst].score);

  gb.display.setCursorX(85);
  gb.display.printf("%d",players[podium.trd].score);

  gb.display.setCursorX(105);
  gb.display.printf("%d",players[podium.fth].score);
}



void Display_TextReady(){
  gb.display.setCursorX(50);
  gb.display.setCursorY(120);
  gb.display.setColor(SetPlayerColor(currentPlayer));
  gb.display.printf("Player %d, Ready?", currentPlayer+1);
}

void Display_TextPlay(){
  gb.display.setCursorX(50);
  gb.display.setCursorY(120);
  gb.display.setColor(SetPlayerColor(currentPlayer));
  gb.display.printf("Player %d, Paint!", currentPlayer+1);
}
