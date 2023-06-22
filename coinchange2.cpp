#include<vector>
long countWaysToMakeChange(int *denominations, int n, int value)
{
   
    vector<long int>prev(value+1,0);
    vector<long int>curr(value+1,0);
    prev[0]=1;
    for(int i=1;i<=value;i++)
    {
        if(value%denominations[0]==0) prev[i]=1;
    }
         
         for(int i=1;i<n;i++)
         {
             for(int j=0;j<=value;j++)
             {
               long  int pick=0;
                 if(j>=denominations[i])
                 pick=curr[j-denominations[i]];
                long int notpick=prev[j];
                 
                 curr[j]=pick+notpick;
             }
             prev=curr;
         }
       return prev[value];
    

}