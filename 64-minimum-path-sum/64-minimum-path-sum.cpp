class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp (n, vector<int> (m,-1));
        dp[0][0] = grid[0][0];
        
        for (int row=0;row<n;row++) {
            for (int col=0;col<m;col++) {
                if (row==0 && col == 0) {
                    dp[row][col] = grid[row][col];
                }
                else  {
                    int up = grid[row][col];
                    int left = grid[row][col];
                    if (row>0) up += dp[row-1][col];
                    else up += INT_MAX/2;
                    
                    if (col>0) left += dp[row][col-1];
                    else left += INT_MAX/2;
                    
                    dp[row][col] = min(up,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};