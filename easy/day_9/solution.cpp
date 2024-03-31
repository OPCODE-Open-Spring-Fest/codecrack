//write your code here
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>arr;
    int t=n;
    while(t>0)
    {
        int r=t%10;
        arr.push_back(r);
        t=t/10;
    }
    sort(arr.begin(),arr.end());
    int i;
    int sum=0;
    for( i=0;i<arr.size();i++)
    {
        if(arr[i]!=0){
            sum+=arr[i];
        break;
    }
    }
    if(sum!=0)
    {
    swap(arr[0],arr[i]);
    int numcheck=0;
    for(int j=0;j<arr.size();j++)
    {
       numcheck=numcheck*10+arr[j];
    }
    if(numcheck==m)
    cout<<"OK"<<endl;
    else
    cout<<"WRONG_ANSWER"<<endl;
    }
    else{
        cout<<"WRONG_ANSWER"<<endl;
    }
    return 0;
}