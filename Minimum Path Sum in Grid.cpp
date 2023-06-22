#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
        vector<int>prev(m,0);
        vector<int>curr(m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0) curr[j]=grid[0][0];
                else
                {     int mod=1e9+7;
                    int left=grid[i][j];int up=grid[i][j];
                    if(j>0) left+=curr[j-1];
                    else
                    left+=mod;
                    
                    if(i>0) up+=prev[j];
                    else
                    up+=mod;
                    
                    curr[j]=min(left,up);
                    
                }
            }
            prev=curr;
        }
        
        return curr[m-1];
}