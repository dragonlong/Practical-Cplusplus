/*
I found that if you would like to be a master in C++, you will need to spend more
time on C++ coding, but we could first get a bite on how general things go with C++:
- char, string, int, float, double;
- max, min, abs;
- struct, class initialization;
- queue, string, vector, map, pqueue;

Some good references:
https://www.jdoodle.com/online-compiler-c++

https://github.com/utkuufuk/cpp-quick-reference#41-vectors
http://www.cplusplus.com/reference/vector/vector/
https://www.codesdope.com/cpp-stdvector/
http://www.cplusplus.com/reference/algorithm/make_heap/ a lot of algorithm

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

//pass by reference/pointer/int
bool compare_xy(int & z, int x, int y)
{
    z = max(x, y);
    return 0;
}

int main() {
	int x=10;
	int y=25;
	int z=1;
	string s="abc";// if you define c here as an string, if you want to redefine it somewhere, it won't be possible;


    bool d = compare_xy(z, x, y);
	cout<<"max of x, y is  " << z <<endl;

	//>>>>>>>>>>>>>>>>-----------string operation--------------<<<<<<<<<<<<<<
	s.push_back('d');
	//c.pop_front();//no pop_front, push_front like API;
	string s1 = s.substr(1, 2);
	string s2 = s + s1;
	//auto c2=c.substr(c.begin(), c.end()); // doesn't work;

	cout<<"String c is: "<<s<<" with size: "<<s.length()<<endl;
	cout<<"Element at 0: "<<s.at(0)<<endl;
	cout<<"String c1 is: "<<s1<<endl;
	cout<<"char c is at index: "<<s.find('c')<<endl;

	//>>>>>>>>>>>>>>>>-----------vector operation--------------<<<<<<<<<<<<<<
	vector<int> v(10, 1);
	vector<int> v1(v);
	vector<int> v2(v.begin(), v.begin()+1);
	v[1] = 1;//if you don't pre-allocate the memory, then it would be segmenttaion fault;

	cout<<"vector v has elements "<<v.size()<<endl;// How to print a vector correctly?
	v.pop_back();
	cout<<"v has front "<<v.front()<<endl;
	//push_back, pop_back;

	//>>>>>>>>>>>>>>>>-----------queue operation--------------<<<<<<<<<<<<<<
	//queue: FIFO queue, push(), pop(), push_back(), pop_front(), front
	//priority_q: always have greatest element at the front(max heap); front, top
	//deque: only this has double ends, that we could use all kinds of operations;
	priority_queue <int, vector<int>, greater<int> > pq; //min heap
	pq.push(3);
	pq.push(1);
  while(!pq.empty())// opposite using !, or we use ==false
  {
      cout<<pq.top()<<endl;
      pq.pop();
  }
  //>>>>>>>>>>>>>>>>-----------objects: classes & struct operation--------------<<<<<<<<<<<<<<
  // declare a struct
  struct CityInfo
  {
      string cityName;
      string state;
      long population;
      int distance;
  };

  // define a struct
  // CityInfo location;
  CityInfo cities[20];

  // initialize a struct
  CityInfo location = {"Asheville", "NC", 50000, 28};
  // access struct members
  location.population = 4750;

  struct Circle
  {
      double radius;
      double diameter;
      double area;
  };

  Circle* cirPtr = new Circle;
  Circle* circles = new Circle[5];

  // access members after dereferencing the struct pointer
  cirPtr->radius = 1.1;
  cirPtr->area = 2.2;

  // array elements are structs, not pointers
  for (int i = 0; i < 5; i++)
  {
      circles[i].radius = 1.1 * i;
      circles[i].area = 2.2 * i;
  }

    // each enumerator is assigned an integer starting from 0
  enum Day
  {
      MONDAY,     // 0
      TUESDAY,    // 1
      WEDNESDAY,  // 2
      THURSDAY,   // 3
      FRIDAY      // 4
  };

  // assign an enumerator to an integer
  int x = THURSDAY;

  // can not directly assign an int to an enum variable
  Day day1 = static_cast<Day>(3);         // day1 = 3 is illegal!!
  Day day2 = static_cast<Day>(day1 + 1);  // day2 = day1 + 1 is illegal!!

  // compare enum values
  bool b = FRIDAY > MONDAY;
	return 0;

}
