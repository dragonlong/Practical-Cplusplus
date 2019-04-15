#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<unordered_map>

using namespace std;
//how could we return from a recursive call
bool find_BlocksOrder(string query, unordered_map<char, vector<int>> availBlocks, int index, vector<int> & flag, vector<int> & sortedBlocks)
{
  if(index>=query.size())
  {
     return true;
  }
  for(int opt=0; opt < availBlocks[query[index]].size(); opt++)
  {
    int indBlock = availBlocks[query[index]][opt];
    if(flag[indBlock]!=1)
    {
      sortedBlocks.push_back(indBlock);
      flag[indBlock]=1;
      bool ret = find_BlocksOrder(query, availBlocks, index++, flag, sortedBlocks);
      if(ret==false)
      {
        sortedBlocks.pop_back();
        flag[indBlock]=0;
      }
     // else return true;
    }
  }
  return false;
}

vector<int> query_blocks(string query, vector<vector<char>> blocks)
{
  vector<int> sortedBlocks;
  unordered_map<char, vector<int>> availBlocks;
  vector<int> flag(query.size(), 0);
  for(int i=0; i < blocks.size(); i++)
  {
    for(int j=0; j < 6; j++)
    {
      auto it= availBlocks.find(blocks[i][j]);
      if(it==availBlocks.end()) availBlocks[blocks[i][j]] = vector<int>();
      availBlocks[blocks[i][j]].push_back(i);
    }
  }
  find_BlocksOrder(query, availBlocks, 0, flag, sortedBlocks);
//  sortedBlocks={0, 1};
  return sortedBlocks;//Error II, what's your return?
}

int main()
{
  string query = "go";
  vector<vector<char>> blocks = {{'o', 'w', 'x', 'y', 'z', 'c'},
                                 {'g', 'c', 'c', 'm', 'd', 'e'}};//Error I, '' is missing
  vector<int> res = query_blocks(query, blocks);//
  cout<<"The matching blocks to the query is "<<res[0]<<' '<<res[1]<<endl;
  return 0;
}
/*
WELCOMETOGOOGLE;
// when to return
if index
0 res{0}
 1
  next item(couldn't find)
    return
    //when to break;


{}*26
map<char, vector<int>>
for(blocks):
  for():
    vect['A'].pusk_back(i);
0(A):{0, 2, 3},
1(B):{1, 2}

{{A,W, E, F, _, G}, {E, D, F, O, _, _}}
*/
