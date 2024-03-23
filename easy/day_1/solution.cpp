#include <bits/stdc++.h>
#define lil long long int
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        lil num; //number of sticks
        cin >> num;

        //creating vector vector instead of array as it is logically incorrect to take input from user and then assign the size of array to that input
        vector<lil> length_of_sticks(num); 
        //stores length of each stick

        for (int i = 0; i < num; i++)
            cin >> length_of_sticks[i];
        //sorting the vector for searching triplets of triangle in vector in single loop
        sort(length_of_sticks.begin() , length_of_sticks.end());

        lil count = 1, ans = 0;
        //count -> keeps track of same length sticks
        //ans-> keeps track of total number of triplets
        //1LL is multiplied to avoid any kind of multiplication overflow
        for (int i = 1; i < num; i++)
        {
            //if the current length of stick is equal to previous one it increments count by one
            if (length_of_sticks[i] == length_of_sticks[i - 1]) 
                count++;

            //if above condition does not holds then it implies count of identical length sticks encountered so far = count
            else
            {
                //calculating number of triplets within group of count
                //count >= 3 then nC3 = n*(n-1)*(n-2)/6
                //add the result to final answer
                if (count >= 3)
                    ans += count *1LL* (count - 1) *1LL* (count - 2) / 6;

                //selecting two elements from group of identical length sticks : nC2 = n*(n-1)/2
                //rest other element = (i-count)
                //add the result to final answer
                if (i - count > 0)
                    ans += count *1LL* (count - 1) / 2 *1LL* (i - count);
                count = 1;
            }
        }

        //after processing all the sticks if there are remaining identical sticks >= 3 then follow the same approach nC3
        if (count >= 3)
            ans += count *1LL* (count - 1) *1LL* (count - 2) / 6;
        //same approach of selecting two elements from identical and rest others
        if (num - count > 0)
            ans += count *1LL* (count - 1) / 2 *1LL* (num - count);
        cout << ans << endl; //Cout is changed to cout
    }
}
