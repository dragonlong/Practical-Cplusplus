#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<ordered_set>
#include<priority_queue>
#include<dqueue>
#include<iterator>
#include<algorithm> 
#include<cstdlib>
#include<math.h>

using namespace std;
int main()
{
  string select_by_type="default";
  int category(0);
  int arr[10]={0}
  switch select_by_type
  {
    case 1 : vector<int> vect(n, 10); // prints "1",
    case 2 : vector<int> vect{10, 20, 30};
    case 3 : vector<vector<int>> vect(10, vector(10, 9)); // then prints "2"
    case 4 :
             {
               vector<int> vect1{ 10, 20, 30 };
               vector<int> vect2(vect1.begin(), vect1.end());
               vector<int> vect3(arr, arr+sizeof(arr)/sizeof(int));
             }
    case 5 : auto vect2(vect1);//copy(vect1.begin(), vect1.end(), back_inserter(vect2));
    default: vector<int> vect;
  }
  vect.push_back(10);
  for (auto it: vect)
  {
    cout<<it<<endl;
  }
  return 0;

}