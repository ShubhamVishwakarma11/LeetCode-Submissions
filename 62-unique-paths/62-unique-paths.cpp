class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n,1));
        
        for (int j=1;j<n;j++) {
            for (int i=1;i<m;i++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
            
        }
        
        return dp[m-1][n-1];
    }
};