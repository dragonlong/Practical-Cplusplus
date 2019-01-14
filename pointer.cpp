#include <iostream>

using namespace std;

void displayPayRates(const double* rates, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << rates[count] << endl;
    }
}

int main () {
   int  var;
   int* ptr;
   int  **pptr;

   var = 3000;

   // take the address of var
   ptr = &var;

   // take the address of ptr using address of operator &
   pptr = &ptr;

   // take the value using pptr
   cout << "Value of var :" << var << endl;
   cout << "Value available at *ptr :" << *ptr << endl;
   cout << "Value available of ptr :" << ptr << endl;
   cout << "Value available at **pptr :" << **pptr << endl;
   cout << "Value available at *pptr :" << *pptr << endl;
   cout << "Value available at pptr :" << pptr << endl;

   // this function accepts a pointer to an array of constants

   return 0;
}
