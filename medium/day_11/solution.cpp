// code by guptaanshuman7

#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;

    while(q--){
        long long n;
        cin>>n;
        
        long long num=9;//num as count_of_number having 1 digit
        int digit=1;
        long long i=0;//counting the number at which k index conincides

        // counting til the digit group is reached 
        while(n>digit*num){
            n-=digit*num;
            i+=num;
            num=num*10;
            digit++;
        }

        cout<<i<<endl;

        // calculating final number
        i+=static_cast<int>(ceil(static_cast<double>(n) / digit));

        cout<<i<<endl;

        // finding coincing index
        char ans=(to_string(i))[(n-1)%digit];

        cout<<ans<<endl;

    }
}
