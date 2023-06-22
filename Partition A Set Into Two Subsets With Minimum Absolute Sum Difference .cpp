#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
   int sum=0;
   for (int i = 0; i < n; i++) {
     sum += arr[i];
   }
   int target = sum;

   vector<int> prev(target + 1, 0);
   vector<int> curr(target + 1, 0);
   prev[0] = 1;
   curr[0] = 1;
   if (target >= arr[0])
     prev[arr[0]] = 1;

   for (int i = 1; i < n; i++){
       for(int j=1;j<=target;j++)
       {
           int pick=false;
           if(j>=arr[i])
           pick=prev[j-arr[i]];
           if(pick==true) 
            curr[j] =pick;
            else
            {
                int notpick=prev[j];
                if(notpick==true)
                curr[j]=notpick;
            }
       }
       prev=curr;
   }
   int mini=1e9+7;
   for(int i=0;i<=target/2;i++)
   {
       if(prev[i]==true)
       {
           mini=min(mini,abs(sum-2*i));
       }
       
   }
   return mini;

}
