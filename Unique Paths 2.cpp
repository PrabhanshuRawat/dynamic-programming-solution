

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int left,right;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   if(mat[i][j]==-1) dp[i][j]=0;
           else if(i==0&&j==0) dp[i][j]=1;
            
            else
            {   if(j==0) left=0;
             else
                left=dp[i][j-1];
             if(i==0) right=0;
             else
                right=dp[i-1][j];
            dp[i][j]=(left+right)%1000000007;}
        }
        
    }
    return dp[n-1][m-1];
}