int targetSum(int n, int d, vector<int>& arr) {
     int sum=0;
      for(int i=0;i<n;i++)
      sum+=arr[i];

     if((sum+d)%2!=0) return 0;

     int target=(sum+d)/2;

     vector<int>prev(target+1,0);
     vector<int>curr(target+1,0);


    if(arr[0]==0) prev[0]=2;
    else  prev[0]=1;
    if((arr[0]<=(sum+d)/2)) 
   {  if(arr[0]!=0) 
       prev[arr[0]]=1;
    else
        prev[arr[0]]=2;}
       

     

     for(int i=1;i<n;i++)
     {
         for(int j=0;j<=target;j++)
         {
             int pick=0;
             if(j>=arr[i])
             pick=prev[j-arr[i]];
             
             int notpick=prev[j];
             
             curr[j]=(pick+notpick)%((int)(1e9+7));
         }
         prev=curr;
     }
     
     return prev[target];
}
