#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int depthsearch( vector<vector<int>>& board, int sr,  int sc, int tr, int tc,)
{
  if(sr==tr && sc==tc)
  {
    return 0;
  }
  if(sr<0 || sr>board.size()-1|| sc<0 || sr>board[0].size())
  {
    return -1;
  }
  else if(board[sr][sc]==0)
  {
    return -1;
  }
  board[sr][sc]=0;
  int len1 = depthsearch(board, sr+1, sc, tr, tc);
  int len2 = depthsearch(board, sr, sc+1, tr, tc);
  int len3 = depthsearch(board, sr-1, sc, tr, tc);
  int len4 = depthsearch(board, sr, sc-1, tr, tc);
  int a[4]={len1, len2, len3, len4};
  int result=1e8;
  for(int i=0;i<4;i++)
  {
    if(a[i]!=-1)
    {
      result=min<int>(result, a[i]);
    }
  }
  if(result==1e9)
  {
    board[sr][sc]=1;
    return -1;
  }
  else{
    return result+1;
  }

}

int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
	// your code goes here
  vector<vector<int>> board(grid);
  int result = depthsearch(board, sr, sc, tr, tc);
  return result;
}
//let's just end here, thanks for your time and suggestions!
int main()
{
	return 0;
}

/*
   s
 [[1, 1, 1, 1],
  [0, 1, 0, 1],
  [1, 1, 1, 1]]
   d

*/
