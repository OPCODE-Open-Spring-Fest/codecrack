// Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
long long int  powe(long long int  x){
    long long int  ans = 1l ;
    for(long long int  i = 1;i<=x;i++){
        ans = ans*2l ;
    }
    return ans;
}
int main() {
    long long int t,n,x;
    cin>>t;
    while(t--){
        long long int  n,x;
        cin>>n>>x;
        vector<int> v1(90),v2(90);
        int i=0;
        while(n>0){  // Converts n  to its binary representation and stores it in v1. If the i-th bit of n is 1, it sets v1[i] to 1.
            if(n&1){
                v1[i] = 1;
            }
            i++;
            n=n/2;
        }
        i = 0;
        while(x>0){  // Similar for x in v2
            if(x&1){
                v2[i] = 1;
            }
            x/=2;
            i++;

        }
        int f = 0;
        for(int i = 89;i>=0;i--){  //   check from the the 89th bit to find the smallest m
            if(v1[i]==0 && v2[i]==1){
                f=1;
            }
        }
        long long int  ans=0;
        for(int i=89;i>=0;i--){  
            if(v1[i] != v2[i]){
                for(int j = i-1;j>=0;j--){
                    if(v2[j]!=0){
                        f=1;
                    }
                }
                if(v1[i+1]==0){
                    ans+=powe(i+1);
                    break;
                }
                else{
                    f=1;
                    break;
                }
            }
            else{
                if(v1[i]==1){
                    ans+=powe(i);
                }
            }
        }
        if(f){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }

    }

}
