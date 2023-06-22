#include <bits/stdc++.h>

long long int house(int j, int bc, vector<int> &valueInHouse) {
    
    
    
      long long  int prev=valueInHouse[bc];
      long long int prev2;
      long long curr;
        
        for(int i=(bc+1);i<(j+1);i++)
        {          
               long long  int pick=valueInHouse[i];
                 if(bc==0)
                 {
                     if(i>1) pick+=prev2;
                 }
                 if(bc==1)
                 {
                     if(i>2) pick+=prev2;
                 }
   long long int nopick=prev;

curr=max(pick,nopick);
prev2=prev;
prev=curr;
        
        }


        
         return prev;
    
   
}

long long int houseRobber(vector<int>& valueInHouse)
{           
    long long int n=valueInHouse.size();
     if(n==1) return valueInHouse[0];
     
    long long int one=house(n-1,1,valueInHouse);
    
    long long int two=house(n-2,0,valueInHouse);
      return max(one,two);

    
}