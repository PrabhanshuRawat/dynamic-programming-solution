#include<iostream>
#include<vector>


int frogJump(int n, vector<int> &heights)
{
    int prev1=0;
    int prev2=0;
    int curr;
     int a=INT_MAX;
     int b=INT_MAX;
    for(int i=1;i<n;i++)
    {
         a=abs(heights[i]-heights[i-1])+prev1;

         if(i>=2)
         b=abs(heights[i]-heights[i-2])+prev2;


         curr=min(a,b);

         prev2=prev1;
         prev1=curr;
        
    }
    return prev1;
}