int knap(int ind,int target,vector<int>& weight,vector<int>& value,int n,vector<vector<int>>& dp)
{
    if(target==0) return 0;
    if(ind==0)
    {
        if(weight[0]<=target) return value[0];
        else
            return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int take=0;
    if(weight[ind]<=target)
        take=value[ind]+knap(ind-1,target-weight[ind],weight,value,n,dp);
    int nottake=knap(ind-1,target,weight,value,n,dp);
    return dp[ind][target]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   int m= maxWeight;
    vector<int>prev(m+1,0);
	for(int i=weight[0];i<=m;i++)
        prev[i]=value[0];
 for(int i=1;i<n;i++)
 {
     for(int j=m;j>=0;j--)
     {
         int take=0;
         if(weight[i]<=j)
             take=value[i]+prev[j-weight[i]];
         int nottake=prev[j];
         prev[j]=max(take,nottake);
     }
     
 }
 
     return prev[m] ;
}