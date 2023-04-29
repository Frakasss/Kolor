#include <Gamebuino-Meta.h>

#include "Define.h"

#include "Map.h"
#include "Utils.h"

#include "img_palettes.h"
#include "img_sprites.h"
#include "img_wallpaper.h"
#include "img_backgrounds.h"
#include "img_map.h"


//navigation
int menu_Item = 0;
int menuPvp_item=0;
int menuCustom_item=0;
int menuCustom_player=0;
bool menuCustom_detail = false;
int menuCustom_detailitem=0;
int menuPauseItem=0;
int selectedWeapon = 0;
int selectedMap = 0;
int firstRowDisplayed=0;

//game
int nbOfPlayer = MAX_NB_PLAYER;
int nbOfCPU = 0;
int currentMap = 0;
GameState currentGameState = GAMEMAKERS;

//gameplay
int previousWalkedState = 1;
int nbOfturn=MAX_NB_OF_TURN;
int currentPlayer = 0;
int anim=0;
bool autoMove=true;
bool areYouReady=false;
int previousShot[4]; //0:UP 1:RIGHT 2:DOWN 3:LEFT 4:EXPLOSE 5:MOVE

PlayerState players[MAX_NB_PLAYER];
Podium podium;

int iapath[8] = {0,0,0,0,0,0,0,0};

bool debugF11 = false;

//IaOptions iaOptions;

void setup() 
{
  gb.begin();
  gb.display.setFontSize(1);
  gb.display.setPalette(PALETTE);
  InitPlayer();
  SetGameState(GAMEMAKERS);
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
      Display_Buttons();
      break;

    case TITLESCREEN:
      Reset();
      ReadPlayerInput_Intro();
      Display_Titlescreen();
      Display_Buttons();
      break;

    case MENU:
      ReadPlayerInput_Menu();
      Display_Menu();
      Display_Buttons();
      break;

    case MENU_PVP:
      ReadPlayerInput_MenuPVP();
      Display_MenuPVP();
      Display_Buttons();
      break;

    case MENU_PVE:
      ReadPlayerInput_MenuPVE();
      Display_MenuPVE();
      Display_Buttons();
      break;

    case MENU_CUSTOM:
      ReadPlayerInput_MenuCustom();
      Display_MenuCustom();
      Display_Buttons();
      break;

    case CREDITS:
      ReadPlayerInput_Credits();
      Display_Credits();
      Display_Buttons();
      break;

    case CHECK:
      Gameplay_CheckWin();
      Display_Game();
      break;

    case LOADMAP:
      Display_Loadmap();
      ScanMap();
      Gameplay_CheckNextPlayer();
      break;
    
    case RUREADY: 
      ReadPlayerInput_Ready();
      Display_Game();
      Display_Ready();
      Display_Buttons();
      Backlight_full(players[currentPlayer].color);
      break;
      
    case IA:
      Display_Game();
      Display_TextPlay();
      Display_CPU();
      IA_LaunchProcessing();
      Backlight_full(players[currentPlayer].color);
      break;

    case IAPROCESSING:
      ReadPlayerInput_IA();
      Display_Game();
      Display_TextPlay();
      Display_CPU();
      IA_Processing();
      Backlight_full(players[currentPlayer].color);
      break;

    case DEBUG:
      Display_Game();
      Display_Debug();
      break;
      
    case PLAY: 
      ReadPlayerInput_Game();
      Display_Game();
      Display_SelectedWeapon();
      Display_Buttons();
      Display_TextPlay();
      Gameplay_CheckNextPlayer();
      break;

    case PAUSE: 
      ReadPlayerInput_Pause();
      Display_Game();
      Display_WeaponMenu();
      Display_Buttons();
      //Display_TextReady();
      break;
      
    case MOVE_UP: 
    case MOVE_DOWN:
    case MOVE_LEFT:
    case MOVE_RIGHT: 
      gb.sound.playOK();
      Gameplay_UpdatePosition();
      Display_Game();
      Display_Buttons();
      Display_TextPlay();
      Gameplay_CheckNextPlayer();
      break;
      
    case EXPLOSE: 
      gb.sound.playCancel();
      Gameplay_Explosion();
      Display_Game();
      Display_TextPlay();
      Gameplay_CheckNextPlayer();
      break;
      
    case WIN:
      Display_Podium();
      Display_Buttons();
      ReadPlayerInput_Win();
      Backlight_full(players[podium.fst].color);
      break;

    case SEEMAP:
      Display_Game();
      Display_Congrats();
      Display_Buttons();
      ReadPlayerInput_SeeMap();
      break;
      
    default: 
      break;
  }
}
