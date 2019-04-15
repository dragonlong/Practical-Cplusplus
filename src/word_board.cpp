#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// dynamic: which variable should be put inside;
// what is the function return and then what;
// every choice shouldn't interrupt with each other;
// class Solution {
// public:

bool find_exist(vector<vector<int>>& track, vector<vector<char>>& board, int x, int y, string& word, int index)
{
int height (board.size()), width(board[0].size());
bool res=false;
if(word.size()==index)
{
    return true;
}
// four possible choices here
if(0<x && track[x-1][y]!=1 && board[x-1][y]==word[index])
{
    //cout<<index<<"going up"<<endl;
    track[x-1][y]=1;
    res=find_exist(track, board, x-1, y, word, index+1);
    if(res) return true;
    track[x-1][y]=0;
}
if(y>0 && track[x][y-1]!=1 && board[x][y-1]==word[index])
{
    //cout<<index<<"going left"<<endl;
    track[x][y-1]=1;
    res=find_exist(track, board, x, y-1, word, index+1);
    if(res) return true;
    track[x][y-1]=0;
}
if(x<height-1 && track[x+1][y]!=1 && board[x+1][y]==word[index])
{
    //cout<<index<<"going down"<<endl;
    track[x+1][y]=1;
    res=find_exist(track, board, x+1, y, word, index+1);
    if(res) return true;
    track[x+1][y]=0;
}
if(y<width-1 && track[x][y+1]!=1 && board[x][y+1]==word[index])
{
    //cout<<index<<"going right"<<endl;
    track[x][y+1]=1;
    res=find_exist(track, board, x, y+1, word, index+1);
    if(res) return true;
    track[x][y+1]=0;
}
//cout<<index<<"all failed"<<endl;
return false;
}

bool find_exist1(vector<vector<char>>& board, int x, int y, string& word, int index)
{
  if(index==word.size())
  {
    return true;
  }
  int height(board.size()), width(board[0].size());
  bool res=false;
  char temp=board[x][y];
  if(x<0 || y<0 || x>=height || y>=width || board[x][y]=='.')
  {
    return false;
  }
  else if (board[x][y]==word[index])
  {
    board[x][y]='.';
    res=find_exist1(board, x-1, y, word, index+1);
    if(res) return true;
    res=find_exist1(board, x, y-1, word, index+1);
    if(res) return true;
    res=find_exist1(board, x+1, y, word, index+1);
    if(res) return true;
    res=find_exist1(board, x, y+1, word, index+1);
    if(res) return true;
    board[x][y]=temp;
  }
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
int height(board.size()), width(board[0].size());
vector<vector<int>> track(height, vector<int>(width, 0));
if(word.size()==0) return true;
for(int i=0;i<height;i++)
{
    for(int j=0;j<width;j++)
    {
        if(board[i][j]==word[0])
        {
            //track[i][j]=1;
            //cout<<"going from("<<i<<","<<j<<") "<<endl;
            //bool result=find_exist(track, board, i, j, word, 1);
            if(find_exist1(board, i, j, word, 0)) return true;
            //track[i][j]=0;
        }
    }
}
return false;
}
// };
//how to clean up this code
//what if I want to return the index
int main()
{
  vector<vector<char>> board={{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
  string word="ABCESEE";
  bool result_final = exist(board, word);
  cout<<"finished running!!!"<<result_final<<endl;
  return 0;
}
