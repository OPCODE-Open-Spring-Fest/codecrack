//Write your solution here
//Write your solution here  
// CODE BY JAGPREET153

#include <bits/stdc++.h>
using namespace std;

void add(vector<int>& v, int temp) {   // Function for adding the element inside the  vector
    if (v.empty() ||v.back()<=temp) {  // if vector is empty or last element is less than the temp 
        v.push_back(temp);
        return;
    }
    int value = v[v.size()-1];
    v.pop_back();
    add(v, temp);
    v.push_back(value);
}

void sorting(vector<int>& v) {
    if (v.size() == 1)  // if vector size is 1
    return;
    int temp=v.back();  
    v.pop_back();   // pop the last element
    sorting(v);
    add(v, temp);  // add the last element in the vector
}

// first we will sort the vector by popping the last element and then calling the sorting function again and again till the size of vector is 1
// and then we will insert the last element in the vector after checking tha last element is greater than the temp or not
int main() {   
    int n,i,x,t;
    cin>>t;
    while(t--)
    {       
        cin >> n;
        vector<int> v;  
        for (i=0;i<n;i++) {  // Taking input in vector
            cin>>x;
            v.push_back(x);
        }
        sorting(v);  // Sorting the vector
        for (int i=0;i<n;i++) {
            cout<<v[i]<< " ";
        }
        cout<<endl;
    }

    return 0;
}

