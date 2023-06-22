#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int>curr(w+1,0);
    
    for(int i=1;i<=w;i++)
    {
        curr[i]=(i/weight[0])*profit[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++)
        {
            int pick=0;
            if(j>=weight[i])
            pick=profit[i]+curr[j-weight[i]];
            int notpick=curr[j];
            
            curr[j]=max(pick,notpick);
        }
        
    }

    return curr[w];
}
