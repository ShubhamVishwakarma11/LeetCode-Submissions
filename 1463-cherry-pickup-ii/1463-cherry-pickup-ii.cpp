class Solution {
public:
     
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)  {
        int n = grid.size();
        int m = grid[0].size();
        
        if (0>j1 || j1>=m) return INT_MIN;
        if (0>j2 || j2>=m) return INT_MIN;
        if (i==n-1) {
            if (j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        
        int maxi = 0;
        for (int a=-1; a<=1;a++) {
            for (int b=-1; b<=1; b++) {
                int curr = 0;
                if (i+1>=n || j1+a<0 || j2+b<0 || j1+a>=m || j2+b>=m) continue;
                if (dp[i+1][j1+a][j2+b] != -1) {
                    curr = dp[i+1][j1+a][j2+b];
                }
                else {
                    curr = f(i+1, j1+a, j2+b, grid,dp);
                    dp[i+1][j1+a][j2+b] = curr;
                }
                if (j1 == j2) {
                    curr += grid[i][j1];
                }
                else {
                    curr += grid[i][j1] + grid[i][j2];
                }
                maxi = max(maxi, curr);
            }
        }
        
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m,-1)) );
        
        return f(0,0,m-1,grid, dp);
    }
};