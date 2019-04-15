#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getDifferentNumber(vector<int>& arr )
{
  // your code goes here
  if(arr.size()==0) return 0;
  // unordered_map<int, int> sorted_array;
  // // sort array
  // for(int i=0;i<arr.size();i++)
  // {
  //   sorted_array[arr[i]]=1;
  // }
  // for(int j=0;j<arr.size();j++)
  // {
  //   if(sorted_array.count(j)==0) return j;
  // }
  // return arr.size();
  for(int i=0;i<arr.size();i++)
  {
    while(arr[i]!=i && arr[i]<arr.size())
    {
      swap(arr[i], arr[arr[i]]);
    }
  }
  for(int i=0;i<arr.size();i++)
  {
    if(arr[i]!=i) return i;
  }
  return arr.size();
}

int main() {
  return 0;
}
