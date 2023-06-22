#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
      vector<int>prev(n);
       vector<int>curr(n);
      for(int i=0;i<n;i++)
      {
          prev[i]=triangle[n-1][i];
      }

      for(int i=n-2;i>=0;i--)
      {
          for(int j=0;j<(i+1);j++)
          {
              int one=triangle[i][j]+prev[j];
              int two=triangle[i][j]+prev[j+1];

              curr[j]=min(one,two);
          }
          
          prev=curr;
      }
      
      return prev[0];

      
}