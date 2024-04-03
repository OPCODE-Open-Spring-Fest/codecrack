// code by guptaanshuman7

#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;

    while(q--){
        long long k;
        cin>>k;

        long long num=9;//num as count_of_numbers_with_digit as 9 numbers have 1 digits
        int digit=1;
        long long i=0;//for number counting

        // finding group with the number of digit in the number having the specified index
        // and counting numbers before the group of that particular digit count
        // increasing digits
        while(k>num*digit){
            i+=num;
            k-=num*digit;
            digit++;
            num=num*10;
        }

        // finding the number (final)
        i+=ceil(k/digit);

        // for finding coinciding digit of number and k index
        int dig=k%digit;
        while(dig--){
            i=i/10;
        }

        cout<<i%10<<endl;
    }
}
