#include<vector>
#include<iostream>

using namespace std;

bool check_choice(vector<vector<char>>& board, int i, int j, int k)
{
  //if one repeated number found, return false
  if(find(board[i].begin(), board[i].end(), char(k)==board[i].end())
    return false;
  for(int m=0;m<9;m++)
  {
    if board[m][j]==char(k) return false;
  }
  int start_r = int(i/3)*3;
  int start_c = int(j/3)*3;
  for(int m=start_r;m<start_r+3;m++)
  {
    for(int n=start_c;n<start_c+3;n++)
    {
      if(board[m][n]==char[k])
        return false;
    }
  }
  board[i][j] = char(k);
  return true;
}

bool sudoku(vector<vector<char>>& board)
{
  // optimize so no need to visit previous nodes
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(i==8 && j==8 && board[i][j]!='_')
        return true;
      else if(board[i][j]!='_')
      {
        for(int k=0;k<9;k++)
        {
          bool valid = check_choice(board, i, j, k);
          if(valid) sudoku(board);
        }
      }
    }
  }
  return false;
}

bool sudokuSolve( const vector<vector<char>>& board )
{
  // your code goes here
  //
  //each blank 9 choices, 0, 1, 2
  //                     //next item
  //                     //next next item
  //                     reach [8][8] position
  auto nboard(board);
  bool res = sudoku(nboard);
  return res;
}

int main()
{
  vecor<vector<char>> board={{'5', '3', '_', '_', '7', '_', '_', '_', '_'},
                             {'6', '1', '_', '_', '9', '5', '_', '_', '_'},
                             {'9', '8', '6'},
                             {'8', '6', '3'},
                             {},
                             {},
                             {},
                             {},
                             {}
                            }
  cout<<"Love you, my rabbit!!"<<endl;
  return 0;
}


// bool soduku(vector<vector>(char)& board, int x, int y)
// {
//   if(board[x][y]!='.')
//   {
//     if(!soduku(board, y==8?x+1:x, y==8?0:y+1))
//       return false;
//   }
//   else
//   {
//
//   }
//
//
// }
// bool sudokuSolve( const vector<vector<char>>& board )
// {
//   // your code goes here
//   bool ret = sudoku(board, 0, 0);
//   return ret;
//   // 5 3 1 -
//
//   for(int i=0;i<board.length;i++){
//     for(int j=0;j<board[0].length;j++){
//       if(bosrd[i][j]=='.'){
//         for(int k=1;k<=9;i++){
//           board[i][j] = (char)k;
//           //check row();
//           // check col;
//           // check the grid
//           bool flag = row&& col && gid;
//           if(flag && sudokuSolve(board)){
//             return true;
//           }
//
//         }
//       }
//     }
//   }
// }
//
// the running time 0(9^m) where m is the  number of empty spaces
