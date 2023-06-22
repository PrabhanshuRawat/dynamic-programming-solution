
int ninjaTraining(int n, vector<vector<int>> &points)
{  vector<int>prev(3,-1),curr(3,-1);
 prev[0]=max(points[0][1],points[0][2]);
 prev[1]=max(points[0][0],points[0][2]);
 prev[2]=max(points[0][0],points[0][1]);
 for(int i=1;i<(n-1);i++)
 {
     
     for(int j=0;j<3;j++)
     {   int maxi=0;
         for(int k=0;k<3;k++)
         {
             if(j!=k)
             { maxi=max(maxi,prev[k]+points[i][k]);
              curr[j]=maxi;}
         }
     }
     prev=curr;
         
 }
 int maxi=0;
 for(int i=0;i<3;i++)
     maxi=max(maxi,points[n-1][i]+prev[i]);
 return maxi;
    
}