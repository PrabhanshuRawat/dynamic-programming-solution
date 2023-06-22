#include <bits/stdc++.h> 


int maximumNonAdjacentSum(vector<int> &nums){
    

int n=nums.size();

vector<int>dp(n,-1);
int prev=nums[0];
int prevtoprev;
int curr;


for(int i=1;i<n;i++)
{     
    int pick=nums[i];
    if(i>1) pick=pick+prevtoprev;
    
    int notpick=prev;
    
    curr=max(pick,notpick);

    prevtoprev=prev;
    prev=curr;
    
    
}
return prev;




    
}