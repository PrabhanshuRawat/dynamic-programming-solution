#include <bits/stdc++.h> 



int getMaxPathSum(vector<vector<int>> &matrix)
{     
    int n=matrix.size();
    int m=matrix[0].size();
      int maxi=-1e9+7;
      vector<int>prev(m);
      vector<int>curr(m);
      for(int i=0;i<m;i++)
      {
          prev[i]=matrix[0][i];
          
      }
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {    int one=-1e9+7,two=-1e9+7,three=-1e9+7;
         one=matrix[i][j]+prev[j];
         if(j>0)
     two=matrix[i][j]+prev[j-1];
     if(j<(m-1))
     three=matrix[i][j]+prev[j+1];

     curr[j]= max(one,max(two,three));
       }
       prev=curr;
   }


    for(int i=0;i<m;i++)
    {   
        maxi=max(maxi,prev[i]);
        

    }
    return maxi;
}