class Solution {
public:
    
    int f (int index, vector<int> &dp) {
        if (index == 0) return 1;
        if (index == 1) return 1;
        
        int l = (dp[index-1] == -1) ? f(index-1,dp) : dp[index-1];
        int r = (dp[index-2] == -1) ? f(index-2,dp) : dp[index-2];
        
        return dp[index] = l+r;
    }
    
    int climbStairs(int n) {
        vector<int> dp (n+1, -1);
        return f(n,dp);
    }
    
    
};