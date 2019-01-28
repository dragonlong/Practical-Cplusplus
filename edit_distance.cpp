#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

int minDistance(string word1, string word2)
{
  int a = word1.size();
  int b = word2.size();
  if(a==0 || b==0)
  {
      return max(a, b);
  }
  int c[a][b];
  int step=0;
  if(word1[0]==word2[0])
  {
      c[0][0] = 0;
  }
  else
      c[0][0] = 1;
  for(int j=1;j<b;j++)
  {
      if(word1[0]==word2[j])
      {
          c[0][j]=j;
      }
      else
      {
          c[0][j] = min(c[0][j-1]+1, j+1);
      }
  }
  for(int i=1;i<a;i++)
  {
      if(word2[0]==word1[i])
      {
          c[i][0] = i;
      }
      else
      {
          c[i][0]= min(i+1, c[i-1][0]);
      }
  }
  for(int i=1;i<a;i++)
  {
      for(int j=1;j<b;j++)
      {
        step = word1[i]==word2[j]?0:1;
        c[i][j]=min(c[i-1][j]+1, min(c[i][j-1]+1, c[i-1][j-1]+step));
      }
  }
  return c[a-1][b-1];
}

int main()
{
  string word1 = "intention";
  string word2 = "execution";
  int index = minDistance(word1, word2);
  cout<<index<<endl;
  return 0;

}
