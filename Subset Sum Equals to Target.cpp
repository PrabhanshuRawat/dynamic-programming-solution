#include <bits/stdc++.h> 




bool subsetSumToK(int n, int k, vector<int> &arr) {
    int target=k;
    
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
     for(int i=0;i<n;i++)
     prev[0]=1;

     curr[0]=1;
     if(target>=arr[0]) prev[arr[0]]=1;

     for(int i=1;i<n;i++){
         for(int j=1;j<=target;j++)
         {  if(!(i==0&&j==arr[0])){
                bool pick=0;
                if(j>=arr[i])
                pick=prev[j-arr[i]];
                if(pick==1){
                    curr[j]=1;
                }
                else
                {
                    bool notpick=prev[j];
                    if(notpick==1) curr[j]=1;


                    
                }



             
         }
             
             
         }
         prev=curr;
     }




     
    return prev[target];


    
}