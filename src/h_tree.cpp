
#include <iostream>
#include<math.h>
void drawLine(double x1, double y1, double x2, double y2) {
  return;
}

void drawHTree(double x, double y, double length, double depth)
{
  if(depth==0) return;
  int len=length;
  drawLine(x-length/2, y, x+length/2, y);
  drawLine(x-length/2, y-length/2, x-length/2,y+length/2);
  drawLine(x+length/2, y-length/2, x+length/2,y+length/2);
  depth--;
  // you could call the functions multiple times, the recursion will handle it automatically
  drawHTree(x-length/2, y+length/2, length/sqrt(2), depth);
  drawHTree(x-length/2, y-length/2, length/sqrt(2), depth);
  drawHTree(x+length/2, y+length/2, length/sqrt(2), depth);
  drawHTree(x+length/2, y-length/2, length/sqrt(2), depth);
}

int main()
{
    double x(0), y(0), length(32), depth(5);
    drawHTree(x, y, length, depth);
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}


/*
|-.-|

(x, y)
 length
*/
