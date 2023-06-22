#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
    //vector<vector<int>>dp(m,vector<int>(n,-1));
	//dp[0][0]=1;
    vector<int>dp(n,0);
    vector<int>temp(n,1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0&&j==0) continue;
            else
             temp[j]=temp[j-1]+dp[j];
        }
        for(int i=0;i<n;i++)
            dp[i]=temp[i];
        
    }
    return temp[n-1];
}