class Solution {
public:
    
    int f (int row, int col, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid) {
        if (row<0 || col<0) return 0;
        if (row ==0 && col ==0) {
            if (obstacleGrid[0][0] == 1) return 0;
            return 1;
        }
        if (dp[row][col] != -1) return dp[row][col];
        
        if (obstacleGrid[row][col] == 1) {
            return dp[row][col] = 0;
        }
        return dp[row][col] = f(row-1,col,dp, obstacleGrid) + f(row,col-1,dp, obstacleGrid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp (n, vector<int> (m,-1));
        
        return f(n-1,m-1,dp,obstacleGrid);
    }
};