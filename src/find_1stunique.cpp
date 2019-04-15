#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<map>

using namespace std;
/*
you learn that:
1. initailize an array with int array[]={0};
2. consider special case like empty string or no unique char string;
3. int [] charCount = new int[26];
4. it's more
*/
int firstUniqChar(string s) {
        //use space to save time
    int count[26]={0};
    int ind_s[26]={0};
    int val=0;
    for(int i=0;i<s.size();i++)
    {
        val = s[i] - 'a';
        if(count[val]==0)
        {
            ind_s[val]=i;
        }
        count[val]+=1;
    }
    val = 1e9;

    for(int j=0;j<26;j++)
    {
        cout<<count[j]<<endl;
        if(count[j]==1)
        {
            if(ind_s[j]<val) val=ind_s[j];
        }
    }
    if(val==1e9) return -1;
    else
      return val;
}
// empty map container
int firstUniqChar_hash(string s)
{
    map<char, int> count;
    for(int i=0;i<s.size();i++)
    {
      count[s[i]]+=1;
    }
    cout<<count.size()<<endl;
    for(int j=0;j<s.size();j++)
    {
      cout<<count[s[j]]<<endl;
      if(count[s[j]] == 1) return j;
    }
    return -1;
}
int main()
{
  //string s="leeltcode";//return 4
  string s="abcdefgabcdefght";//return 14;
  //int val=firstUniqChar(s);
  int val=firstUniqChar_hash(s);
  cout<<val<<endl;
}
