class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev (m,0);
        
        if (obstacleGrid[0][0] == 1) {
            prev[0]=0;
        }
        else prev[0]= 1;
        
        for (int i=0;i<n;i++) {
            vector<int> curr (m,-1);
            for (int j=0;j<m;j++) {
                if (obstacleGrid[i][j] == 1) curr[j] = 0;
                
                else if (j==0) {
                    curr[j] = prev[j];
                }
                else {
                    curr[j] = prev[j] + curr[j-1];
                }
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};