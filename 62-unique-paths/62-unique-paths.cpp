class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> last (m,1);
        
        for (int j=1;j<n;j++) {
            vector<int> curr (m,1);
            for (int i=1;i<m;i++) {
                curr[i] = last[i] + curr[i-1];
            }
            last = curr;
        }
        
        return last[m-1];
    }
};