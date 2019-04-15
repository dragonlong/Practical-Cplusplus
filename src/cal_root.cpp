#include <iostream>
#include <cmath>
//#include <cstdlib>
using namespace std;

double calculateRoot(double x, unsigned int n)
{
  // your code goes here
  if(x==0) return double(0);
  // the format is
  double lowBound(0), highBound(x), midVal((lowBound + highBound)/2);
  double err;
  while(midVal - lowBound >= 0.001)
  {
    cout<<"Current iterated value is: "<<midVal<<endl;
    //err = pow(mid, n) - x;
    err = pow(midVal, n) - x;
    if (err < 0)
    {
      lowBound = midVal;
    }
    else if(err > 0)
    {
      highBound = midVal;
    }
    // add break
    else break;
    // mid value update after that if we're using midVal and for comparison
    midVal = (lowBound + highBound)/2;
  }
  return midVal;
}

int main() {
  double x = 27;
  int n = 3;
  double root = calculateRoot(x, n);
  cout<<"The root of x:"<<x<<", n:"<<n<<" is "<<root<<endl;
  return 0;
}
/*
9, 2  : 3^2 = 9
  //sqrt(9)
  n
  [min=0  max=9]
  mid = 4.5^2 > 9
  max = 4.5
  mid = 2.25^2 <9
  min =


  min^n < x < max^n
  mid = (min+max)/2

  */
