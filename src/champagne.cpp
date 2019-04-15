#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> above_row(query_glass+1, 0);
    vector<double> curr_row(query_glass+1, 0);
    int start = 0;
    int end = 0;
    above_row[0]=max(0, poured-1);
    if(query_row==0)
    {
        return (poured>=1)?1:0;
    }
    for(int i=1;i<query_row;i++)
    {
        start = max(0, query_glass+i-query_row);
        end = min(query_glass+1, i+1);
        for(int j=start;j<end;j++)
        {
            if(j==0)
            {
                curr_row[0]=max<double>(above_row[0]/2-1, 0);
            }
            else if(j==i)
            {
                if(i>query_row-query_glass)
                {
                    curr_row[j-start]=max<double>(above_row[j-start]/2-1, 0);
                }
                else
                {
                    curr_row[j-start]=max<double>(above_row[j-start-1]/2-1, 0);
                }

            }
            else
            {
                if(i>query_row-query_glass)
                {
                    curr_row[j-start]=max<double>(0, (above_row[j-start] + above_row[j-start+1])/2-1);
                }
                else
                {
                    curr_row[j-start]=max<double>(0, (above_row[j-start-1] + above_row[j-start])/2-1);
                }
            }
        }
       above_row = curr_row;
    }
    if(0<query_glass<query_row)
    {
       return min<double>(1, (above_row[0]+above_row[1])/2);
    }
    else
    {
        return min<double>(1, above_row[0]/2);
    }

};


int main()
{
  cout<<"program for solving champagneTower problem"<<endl;
  double volume = champagneTower(8, 3, 3);
  cout<<"The volume is "<<volume<<endl;
}
