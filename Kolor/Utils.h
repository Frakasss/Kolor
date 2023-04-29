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

//######################################################## CHECK FUNCTIONS
bool HasCollision(int nextPosX, int nextPosY)
{
  bool check = false;
  if(nextPosX<0){check=true;}
  if(nextPosY<0){check=true;}
  if(nextPosX>MAP_WIDTH-1){check=true;}
  if(nextPosY>MAP_HEIGHT-1){check=true;}

  if(check==false){
    if(map_layout[nextPosY][nextPosX]==0){check=true;}
    if(map_layout[nextPosY][nextPosX]==6){check=true;}
    if(map_layout[nextPosY][nextPosX]==7){check=true;}
    if(map_layout[nextPosY][nextPosX]==8){check=true;}
    if(map_layout[nextPosY][nextPosX]==9){check=true;}
  }
  return check;
}

int PosValue(int x, int y){
  bool check = false;
  if(x<0){return 0;}
  if(y<0){return 0;}
  if(x>MAP_WIDTH-1){return 0;}
  if(y>MAP_HEIGHT-1){return 0;}

  if(check==false){
    return map_layout[y][x];
  }
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

int intLength(int value){
  int myLength = 1;
  if(value>9){myLength=2;}
  if(value>99){myLength=3;}
  if(value>999){myLength=4;}
  if(value>9999){myLength=5;}
  if(value>99999){myLength=6;}
  return myLength;
}

#endif
