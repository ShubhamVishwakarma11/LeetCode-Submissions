class Solution {
public:
    
    int f (int row, int col, vector<vector<int>> &dp, vector<vector<int>> &triangle) {
        if (row == 0 && col == 0) return triangle[0][0];
        if (row<0 || col<0 || col>row) return 1e4;
        
        if (dp[row][col] != INT_MIN) return dp[row][col];
        int left = f(row-1, col-1,dp,triangle) + triangle[row][col];
        int right = f(row-1, col,dp,triangle) + triangle[row][col];
        
        return dp[row][col] = min (left,right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int res = INT_MAX;
        vector<vector<int>> dp (n, vector<int> (n, INT_MIN));
        for (int i=0;i<n;i++) {
            res = min (res, f(n-1,i,dp,triangle));
            cout << f(n-1,i,dp,triangle) << ' ';
        }
        
        return res;
    }
};