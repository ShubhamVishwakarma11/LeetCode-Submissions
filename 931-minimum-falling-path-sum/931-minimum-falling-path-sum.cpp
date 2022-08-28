class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev (n,0);
        
        for (int row=0;row<n;row++) {
            vector<int> dp (n,0);
            for (int col=0;col<n;col++) {
                // if (row==0){
                //     prev[col] = matrix[0][col];  
                //     continue;
                // } 
                int ld = INT_MAX, rd = INT_MAX;
                int up = prev[col];
                if (col!=0) {
                    ld = prev[col-1];
                }
                if (col!=n-1) {
                    rd = prev[col+1];
                }
                
                dp[col] = matrix[row][col] + min(ld,min(up,rd));
            }
            prev = dp;
        }
        
        int res = INT_MAX;
        for (int i=0;i<n;i++) {
            res = min (res, prev[i]);
        }
        
        return res;
    }
};