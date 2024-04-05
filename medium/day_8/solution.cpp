//Write your code here
#include <bits/stdc++.h>
using namespace std;
int getlength(string str, int idx1, int idx2)//this function returns the length of repeating sequence of string
{
    int count = 0;//count shows how many continuous characters are repeating
    while (idx1 < idx2 && idx2 < str.length())
    {
        if (str[idx1] == str[idx2])
        {
            idx1++;
            idx2++;
            count++;
        }
        else
            break;
    }
    return count;
}
int main()
{
    string str;
    cin >> str; // input the string
    int i = 0;
    int maxLen = INT_MIN, len = 1;
    bool flag = false; //flag shows if any character is repeating
    while (i < str.length())//iterating over the string
    {
        if (str.find(str[i], i + 1) != string::npos) // if string find any repeating characters
        {
            flag = true;    //character repeats so put flag to true
            len = getlength(str, i, str.find(str[i], i + 1));//now get the length of repeating sequence
            if (len > maxLen)
            {
                maxLen = len;//if length of current repeating sequence is greater than len of 
                             //maximum repeating sequence till now, then update maxlen
            }
        }
        i++;
    }
    if (flag)//if flag is true means there is atleast one repeating sequence
        cout <<  maxLen << endl;
    else
        cout << -1 << endl;
    return 0;
}
