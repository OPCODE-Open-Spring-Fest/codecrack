//Write your code here
// Code by Jagpreet153
//Approach broken sticks are stored in a vector and the gaps between the sticks are stored in another vector and the sum of the first n-k elements of the gaps vector is calculated and added to n and then printed.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int x,n,m,k,i;
    cin>>n>>m>>k;
    vector<long long int> broken,gaps;
    for(i=0;i<n;i++) {
        cin>>x;
        broken.push_back(x);
    }
    sort(broken.begin(), broken.end());
    for(i=1;i<n;i++) {
        gaps.push_back(broken[i]-broken[i-1]-1);
    }
    sort(gaps.begin(), gaps.end());
    long long int total = 0;
    for(i=0;i<n-k;i++) {
        total+=gaps[i];
    }
    cout<<total+n<<endl;
    return 0;
}