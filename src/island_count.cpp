#include<vector>
#include<iostream>

using namespace std;
/*
the goal here is to solve the problem: count all isolated 1
[[0,    1,    0,    1,    0],
 [0,    0,    1,    1,    1],
 [1,    0,    0,    1,    0],
 [0,    1,    1,    0,    0],
 [1,    0,    1,    0,    1] ]
*/
// decalre here as defined below;
void mark_allconnetced(vector<vector<int>>& grid, int x, int y);
int getNumberOfIslands(vector<vector<int>>& binaryMatrix)
{
  int result=0; //!!! must initialize a variable
  int row(binaryMatrix.size()), col(binaryMatrix[0].size());
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      //count_islandmark(binaryMatrix, i, j, result);
      //better to have this condition
      if(binaryMatrix[i][j]==1)
      {
        result++;
        //given the board, index position(mark [i,j], look around and repeat)
        mark_allconnetced(binaryMatrix, i, j);
      }
    }
  }
  return result;
}

void mark_allconnetced(vector<vector<int>>& grid, int x, int y)
{
  // be careful with your variable range
  if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return;
  if(grid[x][y]==1)
  {
    grid[x][y]=0;
    mark_allconnetced(grid, x-1, y);
    mark_allconnetced(grid, x+1, y);
    mark_allconnetced(grid, x, y-1);
    mark_allconnetced(grid, x, y+1);
  }

}

int main()
{
  vector<vector<int>> land={{0,    1,    0,    1,    0},
                            {1,    0,    1,    1,    1},
                            {1,    0,    0,    1,    0},
                            {0,    1,    1,    0,    0},
                            {1,    0,    1,    0,    1}
                            };
  int count = getNumberOfIslands(land);
  cout<<"Thanks for your love, little rabbit"<<endl;
  cout<<"The result of island counting is "<<count<<endl;
  return 0;

}
