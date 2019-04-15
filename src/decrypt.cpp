#include <iostream>
#include <string>

using namespace std;

string decrypt( const string& word )
{
  // your code goes here
  string decrypted;
  int temp=1;
  for (int i=0;i<word.size();i++)
  {
    int val=int(word[i]) - temp%26;
    while(val>122 || val< 97)
    {
      val+=26;
    }
    decrypted.push_back(char(val));
    temp = val+temp;
  }
  return decrypted;
}

int main() {
  return 0;
}
/*
new[0] = x[0] + 1;                   97-97+26
new[1] = x[1] + x[0] + 1 - k * 26;
new[2] = x[2] + x[1] + x[0] + 1 - k * 26;

x[0] = new[0] - 1;                   99
x[1] = new[1] - new[0] + k * 26;     10 + k * 26 = 97 - 122 = 114;
x[2] = new[2] - new[1] + k * 26;

*/
k >
