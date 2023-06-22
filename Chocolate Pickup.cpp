
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==j) dp[r-1][i][j]=grid[r-1][j];
                else
                    dp[r-1][i][j]=grid[r-1][i]+grid[r-1][j];
            }
        }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<c;k++)
            {  int maxi=-1e8;
                for(int k1=-1;k1<=1;k1++)
                {
                    for(int k2=-1;k2<=1;k2++)
                    {  if((j+k1>=0)&&(j+k1<c)&&(k+k2>=0)&&(k+k2<c)){
                    if(j==k) maxi=max(maxi,(grid[i][j]+dp[i+1][j+k1][k+k2]));
                        
                     else
            maxi=max(maxi,grid[i][j]+grid[i][k]+dp[i+1][j+k1][k+k2]);
                     
                    }
                     else
                         maxi=max(maxi,(int)-1e8);
                    }
                }
             dp[i][j][k]=maxi;
            }
        }
    }
    return dp[0][0][c-1];
}