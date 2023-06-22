#include <bits/stdc++.h> 
int findWays(vector<int> &nums, int tar)
{         int n=nums.size();
       vector<int>prev(tar+1,0);
       vector<int>curr(tar+1,0);
       
       
         if(nums[0]==0)
          prev[0]=2;
         else 
          prev[0]=1;

          if(tar>=nums[0])
          {
              if(nums[0]!=0) prev[nums[0]]=1;
              else
              prev[0]=2;
          }


       for(int i=1;i<n;i++){
           for(int j=0;j<=tar;j++)
           {
               int pick=0;
               if(j>=nums[i])
               pick=prev[j-nums[i]];
               int notpick=prev[j];

               curr[j]=pick+notpick;
           }
           prev=curr;
       }

    return prev[tar];
    
}

