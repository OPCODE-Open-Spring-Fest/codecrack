#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

// Define a vector of pairs to store segments
vector<pair<int,int> > segments;

int main()
{
    // Number of segments
    int num_segments;
    scanf("%d",&num_segments);

    // Read segments and store them in the vector
    for(int i=1;i<=num_segments;i++)
    {
        // Left and right endpoints of the segment
        int left, right;
        scanf("%d%d",&left,&right);
        // Add starting point of the segment with value 1
        segments.push_back(make_pair(left,1));
        // Add ending point of the segment with value -1
        segments.push_back(make_pair(right+1,-1));
    }

    // Sort the segments based on their left endpoints
    sort(segments.begin(),segments.end());

    // Counter to keep track of the number of active segments at any point
    int active_segments_count=0;

    // Iterate through the sorted segments
    for(int i=0;i<(int)segments.size();i++)
    {
        // Update the counter based on the current segment's value
        active_segments_count+=segments[i].second;
        // If at any point more than 2 segments overlap, print "NO" and exit
        if(active_segments_count>2) return 0*printf("NO\n");
    }

    // If no point has more than 2 overlapping segments, print "YES"
    return 0*printf("YES\n");
}
