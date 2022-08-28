class Solution {
public:
    
    int f (int row, int col,vector<vector<int>> &dp ,vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (row<0 || col<0 || row>=n || col>=n) {
            return INT_MAX;
        }
        if (row==0) return matrix[0][col];
        
        if (dp[row][col] != -101) return dp[row][col];
        int ld = f(row-1,col-1,dp,matrix);
        int up = f(row-1,col,dp,matrix);
        int rd = f(row-1,col+1,dp,matrix);
        
        return dp[row][col] = matrix[row][col] + min(ld,min(up,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n,-101));
        
        int res = INT_MAX;
        for (int i=0;i<n;i++) {
            res = min(res, f(n-1,i,dp,matrix));
        }
        
        return res;
    }
};