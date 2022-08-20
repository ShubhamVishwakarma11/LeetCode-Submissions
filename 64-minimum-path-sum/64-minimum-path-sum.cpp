class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev (m,INT_MAX/2);
        prev[0] = 0;
        
        for (int row=0;row<n;row++) {
            vector<int> curr (m,0);
            for (int col=0;col<m;col++) {
                if (row==0 && col == 0) {
                    curr[col] = grid[row][col];
                }
                else  {
                    int up = grid[row][col];
                    int left = grid[row][col];
                    if (row>0) up += prev[col];
                    else up += INT_MAX/2;
                    
                    if (col>0) left += curr[col-1];
                    else left += INT_MAX/2;
                    
                    curr[col] = min(up,left);
                }
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};