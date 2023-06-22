#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int x)
{   int n=num.size();
     vector<int>prev(x+1,1e9+7);
      vector<int>curr(x+1,1e9+7);
       for(int i=0;i<=x;i++)
       {
           if(i%num[0]==0) prev[i]=i/num[0];

       }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=x;j++)
            {
                int pick=1e9+7;
if(j>=num[i])
pick=1+curr[j-num[i]];

int notpick=prev[j];
      curr[j] =   min(pick,notpick);
            }
            prev=curr;
        }


       if(prev[x]==1e9+7) return -1;
    return prev[x];
}