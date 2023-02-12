#ifndef UTILS_H
#define DEFINE_H

//######################################################## DEFINE VAR
#define CHAR_WIDTH 6
#define CHAR_HEIGHT 6

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 128

#define MAP_WIDTH 26
#define MAP_HEIGHT 18

enum GameState{
    IDLE,
    GAMEMAKERS,
    TITLESCREEN,
    MENU,
    RUREADY,
    PLAY,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    EXPLOSE,
    WIN
};

typedef struct{
  int16_t x; 
  int16_t y;
  int16_t cptAnim;
  int16_t state;
  int16_t dir;
  int16_t score;
}PlayerState;

typedef struct{
  int16_t fst; 
  int16_t snd;
  int16_t trd;
  int16_t fth;
}Podium;

#endif
