//count number of ways to reach Nth stair


#include<iostream>
int countDistinctWays(int nStairs) {
    
    
    int prev1=1;
    int prev2=1;
    int curr;
    int mod=(int)(1e9+7);
    for(int i=2;i<=nStairs;i++)
    {
        curr=(prev1+prev2)%mod;
        prev2=prev1;
        prev1=curr;
    }
    return prev1%mod;
}