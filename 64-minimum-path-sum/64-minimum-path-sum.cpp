class Solution {
public:
    
    int f (int row, int col, vector<vector<int>> &dp,vector<vector<int>> &grid) {
        if (row == 0 && col == 0) {
            return grid[0][0];
        }
        if (row<0 || col<0) return INT_MAX/2;
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int up = f(row-1,col,dp,grid) + grid[row][col];
        int left = f(row,col-1,dp,grid) + grid[row][col];
        
        return dp[row][col] = min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp (n,vector<int> (m,-1));
        
        return f(n-1,m-1,dp,grid);
    }
};