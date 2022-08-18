class Solution {
public:
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> grid;
        for (int i=1;i<=n;i++) {
            vector<int> v (i,1);
            grid.push_back(v);
        }
        
        for (int row=2;row<n;row++) {
            for (int col=1;col<row;col++) {
                grid[row][col] = grid[row-1][col-1] + grid[row-1][col];
            }
        }
        
        return grid;
    }
};