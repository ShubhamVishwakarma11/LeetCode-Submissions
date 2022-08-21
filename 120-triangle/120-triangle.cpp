class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n,INT_MIN));
        
        for (int row=0;row<n;row++) {
            for (int col=0;col<=row;col++) {
                if (row==0) {
                    dp[0][0] = triangle[0][0];
                }
                else if (col==0) {
                    dp[row][col] = dp[row-1][col] + triangle[row][col];
                }
                else if (row == col) {
                    dp[row][col] = dp[row-1][col-1] + triangle[row][col];
                }
                else {
                    int left = dp[row-1][col-1] + triangle[row][col];
                    int right = dp[row-1][col] + triangle[row][col];
                    dp[row][col] = min (left,right); 
                }
            }
        }
        
        int res = dp[n-1][0];
        for (auto it : dp[n-1]) {
            if (it<res) res = it;
        }
        
        return res;
    }
};