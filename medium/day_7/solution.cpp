//write your code here
//Code by Omji Kesharwani
//Sliding Window Approach
#include <iostream>
using namespace std;
#include<vector>
#include<unordered_map>
int countSubArrays(vector<int>& arr,int k)
{
    int left=0;
    int right=0;
    int totalCount=0;
    unordered_map<int,int>mp;
    int n =arr.size();
    while(right<n)
    {
        mp[arr[right]]++;
        while(mp.size()>k)
        {
            mp[arr[left]]--;
            if(mp[arr[left]]==0)
            mp.erase(arr[left]);
            left++;
        }
        totalCount+=right-left+1;
        right++;
    }
    return totalCount;
}
int main()
{
    int n,k;
    cin>>n;// no of elements in the array
    cin>>k;// k distinct values in the subarray
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<countSubArrays(arr,k)<<endl;
    return 0;
}