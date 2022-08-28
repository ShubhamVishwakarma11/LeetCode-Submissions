class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n,-101));
        
        for (int row=0;row<n;row++) {
            for (int col=0;col<n;col++) {
                if (row==0){
                    dp[0][col] = matrix[0][col];  
                    continue;
                } 
                int ld = INT_MAX, rd = INT_MAX;
                int up = dp[row-1][col];
                if (col!=0) {
                    ld = dp[row-1][col-1];
                }
                if (col!=n-1) {
                    rd = dp[row-1][col+1];
                }
                
                dp[row][col] = matrix[row][col] + min(ld,min(up,rd));
            }
        }
        
        int res = INT_MAX;
        for (int i=0;i<n;i++) {
            res = min (res, dp[n-1][i]);
        }
        
        return res;
    }
};