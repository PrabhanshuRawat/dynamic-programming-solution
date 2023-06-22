// program to calculate nth fibonacci number by dynamic programming


class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
       int prev=1;
        int prev_to_prev=0;
         int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev_to_prev;
            prev_to_prev=prev;
            prev=curr;
        }
        return prev;
    }
};