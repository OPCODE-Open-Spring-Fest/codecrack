//code by Jagpreet153
// Approach stored the duration and deadline in a map and then iterated over the map and calculated the reward for each task and added it to the ans variable and then printed the ans variable.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,d;
    cin>>n;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        cin>>a>>d;
        m.insert({a,d});
    }
    int res=0,ct=0,reward=0,ans=0,ctf=0;
    for(auto itr:m)
    {
        int duration = itr.first;
        int deadline = itr.second;
        ct=duration;
        ctf+= ct;       // The time taken to complete the task
        int reward = deadline - ctf;  // The reward for the task
        ans += reward;  // The total reward
    }
    cout<<ans<<endl;
}