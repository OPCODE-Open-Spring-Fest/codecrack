#include <bits/stdc++.h>
using namespace std;
string getsequence(string str, int idx1, int idx2) // this function returns the repeating sequence of string starting with str[i]
{

    string temp = ""; // temp shows the repeating sequence
    while (idx2 < str.length())
    {
        if (str[idx1] == str[idx2])
        {
            temp += str[idx1];
            idx1++;
            idx2++;
        }
        else
            break;
    }
    return temp;
}
int main()
{
    string str;
    string AnsStr;
    cin >> str; // input the string
    int i=0;
    int MaxLength=INT_MIN;
    while(i<str.length())//iterate over the string
    {
        int j=i;
        while(j<str.length())//j represents all the indices where str[i] occurs except the first occurence
        {
            j=str.find(str[i],j+1);
            if(j==-1) break; // if there is no more occurence of str[i] is left then we break the loop
            string temp = getsequence(str,i,j);//get the sequence of string which is repeating
            int len=temp.length();
            if(len > MaxLength)  //if length of current repeating sequence is greater than previously stored length
            {               // then update max length 
                AnsStr=temp;//store max repeating sequence in AnsStr
                MaxLength=len;
            }
        }
        i++;
    }
    cout<<AnsStr<<endl;
    return 0;
}