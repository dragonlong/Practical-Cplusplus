#include<iostream>
#include<string>
#include<vector>

#include<map>
#include<unordered_map>

#include<set>
#include<unordered_set>

#include<deque>
#include<queue> //#include<priority_queue>

#include<iterator>
#include<algorithm> 
#include<cstdlib>
#include<math.h>

using namespace std;
int main()
{
  int select_by_type=1;
  int n = 3;
  int category(0);
  int arr[10]={0};
  vector<int> vect0{0, 1, 2};
  vector<int> vect1;

  int i = 2;
  switch (i) {
	case 1: std::cout << "1";
	case 2: std::cout << "2";   //execution starts at this case label
	case 3: std::cout << "3";
	case 4:
	case 5: std::cout << "45";
	        break;              //execution of subsequent statements is terminated
	case 6: std::cout << "6";
	}
 
  // switch(select_by_type)
  // {
  //   // case 1 : vector<int> vect1(n, 10); // prints "1",
  //   // case 2 : vector<int> vect1{10, 20, 30};
  //   // case 3 : vector<vector<int>> vect1(10, vector<int>(10, 9)); // then prints "2"
  //   // case 4 :
  //   //          {
  //   //            vector<int> vect1{ 10, 20, 30 };
  //   //            vector<int> vect2(vect1.begin(), vect1.end());
  //   //            vector<int> vect3(arr, arr+sizeof(arr)/sizeof(int));
  //   //          }
  //   // case 5 : auto vect1(vect0);//copy(vect1.begin(), vect1.end(), back_inserter(vect2));
  //   // default: vector<int> vect1;
  //   case 1: vect1 = vector<int>(10, 9);
  //   default: vect1 = {1, 2, 3};
  // }
  // vector<int> vect1 = vect0;
  vect1.push_back(10);
  for (auto it: vect1)
  {
    cout<<it<<endl;
  }

  // for(auto it: vect0)
  // {
  //   cout<<it<<endl;
  // }
  return 0;
}