#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int findBusiestPeriod(vector<vector<int>>& data)
{
  int currPeople(0), maxPeople(0), resTime;
  for(int row = 0; row < data.size(); row++)
  {
    // first do something
    if(data[row][2]==1) currPeople+=data[row][1];
    else currPeople-=data[row][1];
    // then decide whether I need to move to the critical part
    if(row == data.size()-1 || data[row][0] != data[row+1][0])
    {
      if(currPeople>maxPeople)
      {
        resTime = data[row][0];
        maxPeople = currPeople;
      }
    }
  }
  return resTime;
}

int main()
{
  vector<vector<int>> data =  {{1487799425, 14, 1},
           {1487799425, 4,  0},
           {1487799425, 2,  0},
           {1487800378, 10, 1},
           {1487801478, 18, 0},
           {1487801478, 18, 1},
           {1487901013, 1,  0},
           {1487901211, 7,  1},
           {1487901211, 7,  0}};
  int resTime = findBusiestPeriod(data);
  cout<<"I love Yiyu!!"<<" Result is "<< resTime<<endl;
  return 0;
}

/*
data = [ [1487799425, 14, 1],
         [1487799425, 4,  0],
         [1487799425, 2,  0],
         [1487800378, 10, 1],
         [1487801478, 18, 0],
         [1487801478, 18, 1],
         [1487901013, 1,  0],
         [1487901211, 7,  1],
         [1487901211, 7,  0] ]
*/
