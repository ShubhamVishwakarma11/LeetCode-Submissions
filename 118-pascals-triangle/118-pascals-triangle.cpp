class Solution {
public:
    
    int f (int row, int col, vector<vector<int>> &grid) {
        if (col == 0) return 1;
        if (row == col) return 1;
        if (grid[row][col] != 1) return grid[row][col];
        return grid[row][col] = f(row-1,col-1,grid) + f(row-1,col,grid);
    }
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> grid;
        for (int i=1;i<=n;i++) {
            vector<int> v (i,1);
            grid.push_back(v);
        }
        
        for (int i=0;i<n;i++) {
            grid[n-1][i] = f(n-1,i,grid);
        }
        
        return grid;
    }
};