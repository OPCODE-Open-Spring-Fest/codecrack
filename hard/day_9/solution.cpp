//write your code here
// Approach:
// The approach to solve this problem is as follows:
// 1 .Initialize a 2D array (matrix) of size n x n.
// 2. Fill the matrix with numbers from 1 to n - 1 in a cyclic manner, excluding the main diagonal and the last row and column.
// 3. Copy the diagonal elements to the last row and column to make the matrix symmetric.
// 4. Set the main diagonal elements to 0.
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	vector<vector<int>> mat(n);
	for (i=0;i<n;i++)
	{
		mat[i].resize(n);   // It alters the container’s content in actual by inserting or deleting the elements from it
	}
	for (i=0;i<n-1;i++)
	{	
		for (j=0;j<n-1;j++)
		{
			mat[i][j]=1+(i+j)%(n-1);    // Fill the matrix with numbers from 1 to n - 1 in a cyclic manner
		}
	}
	
	// Copy the diagonal elements to the last row and column
	//since n<=1000 so we can apply two loops without getting tle
	for (i=0;i<n;i++)
	{
		mat[i][n-1]=mat[i][i];
		mat[n-1][i]=mat[i][i];
		mat[i][i]=0;  // Set the main diagonal elements to 0
	}
	for(i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";  // Printing the required result
		}
		cout << endl;
	}
	return 0;
}
