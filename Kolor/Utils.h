#ifndef UTILS_H
#define UTILS_H




//######################################################## GlOBAL FUNCTIONS
int fmax(int a, int b){  return a > b ? a : b;}

int fmin(int a, int b){  return a < b ? a : b;}

int clamp(int value, int minValue = 0, int maxValue = 1){
  return max(min(value, maxValue), minValue);
}



//######################################################## CHECK FUNCTIONS
bool canPaint(int y, int x){
  bool check = false;
  if(y>0 && y<MAP_HEIGHT-1 && x>0 && x<MAP_WIDTH-1){
    if(map_layout[y][x]>=1 && map_layout[y][x]<=5){check=true;}
  }
  return check;
}

bool HasCollision(int nextPosX, int nextPosY)
{
  bool check = false;
  if(map_layout[nextPosY][nextPosX]==0){check=true;}
  if(map_layout[nextPosY][nextPosX]==6){check=true;}
  if(map_layout[nextPosY][nextPosX]==7){check=true;}
  if(map_layout[nextPosY][nextPosX]==8){check=true;}
  if(map_layout[nextPosY][nextPosX]==9){check=true;}
  return check;
}


Color SetPlayerColor(int player){
  Color playerColor = WHITE;
  switch(player){
    case 0: playerColor=RED; break;
    case 1: playerColor=BLUE; break;
    case 2: playerColor=GREEN; break;
    case 3: playerColor=YELLOW; break;
    default:playerColor=WHITE; break;
  }
  return playerColor;
}

/***********
 * CheckWin *
 ***********/
bool CheckWin()
{
  for (int i=0; i<MAP_HEIGHT; i++)
  {
    for (int j=0; j<MAP_WIDTH; j++)
    {
      if (map_layout[i][j] == 1)
      {
        return false;
      }
    }
  }
  return true;
}

#endif
