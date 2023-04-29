#ifndef DEFINE_H
#define DEFINE_H

//######################################################## DEFINE VAR
#define CHAR_WIDTH 6
#define CHAR_HEIGHT 6

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 128

#define MAP_WIDTH 26
#define MAP_HEIGHT 18

#define MAX_NB_OF_TURN 8
#define MAX_NB_PLAYER 4

enum GameState{
    IDLE,
    DEBUG,
    GAMEMAKERS,
    TITLESCREEN,
    MENU,
    MENU_PVP,
    MENU_PVE,
    MENU_CUSTOM,
    CREDITS,
    CHECK,
    LOADMAP,
    RUREADY,
    IA,
    IAPROCESSING,
    PLAY,
    PLAYIA,
    PAUSE,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    EXPLOSE,
    WIN,
    SEEMAP
};

typedef struct{
  int16_t x; 
  int16_t y;
  int16_t cptAnim;        //to be used if animation on characters
  int16_t state;          //to be used if gameplay include 'freeze', 'colorchange', ... temporary changes
  int16_t dir;            //to be used for direction display
  int16_t score;          //nb of cells colored with player color
  Color color;
  int16_t paintValue;
  int16_t weapon;
  int playerType;         //0: human  //1: cpu   //2:disabled
  char userName[10];
}PlayerState;

typedef struct{
  int16_t fst; 
  int16_t snd;
  int16_t trd;
  int16_t fth;
}Podium;


typedef struct{
  int16_t x;
  int16_t y;
}Coord;

#endif
