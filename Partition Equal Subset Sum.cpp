bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    
    if(sum&1) return false;
    
    int target=sum/2;
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    prev[0]=1;
    curr[0]=1;
    if(target>=arr[0]) prev[arr[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {   
            int pick=false;
            if(j>=arr[i])
            pick=prev[j-arr[i]];
             if(pick==true)
              curr[j]=pick;
            else
            {
                int notpick=prev[j];
                if(notpick==true)
                curr[j]=notpick;
            }
        }
        prev=curr;
    }
    
    return prev[target];
}
