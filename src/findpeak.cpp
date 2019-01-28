#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

int findPeakElement(vector<int>& nums)
{
    int right= nums.size()-1;
    int left = 0;
    // int mid=0;
    int mid=(left+right)/2;
    cout<<mid<<endl;
    while(right>mid)
    {
        cout<<"entering loop"<<endl;
        if(nums[mid+1]>nums[mid])
        {
            left = mid+1;
        }
        else if(nums[mid-1]>nums[mid])
        {
            right=mid-1;
        }
        else
        {
            return mid;
        }
        mid=(left+right)/2;
    }
    return mid;
}

int main()
{
  // int arr[] = { 10, 20, 30 };
  // int n = sizeof(arr) / sizeof(arr[0]);
  // vector<int> vect(arr, arr + n);
  //vector<int> a{1,2,1,3,5,6,4};//should either return 1/5;
  //vector<int> a{1,2,3,1};//should return 2;
  //vector<int> a{2,1};//should return 0
  //vector<int> a{-2,-1};//should return 1
  vector<int> a{-2147483648,-2147483647};
  int index = 0;
  int res = a[1]>a[0]?1:0;
  cout<<a[-2]<<" "<<a[2]<<endl;
  cout<<"a[1]>a[0]: "<<res<<endl;
  index = findPeakElement(a);
  cout<<index<<endl;
  return 0;

}
