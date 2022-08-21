class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,INT_MIN);
        
        for (int row=0;row<n;row++) {
            vector<int> curr (n,INT_MIN);
            for (int col=0;col<=row;col++) {
                if (row==0) {
                    curr[0] = triangle[0][0];
                }
                else if (col==0) {
                    curr[col] = prev[col] + triangle[row][col];
                }
                else if (row == col) {
                    curr[col] = prev[col-1] + triangle[row][col];
                }
                else {
                    int left = prev[col-1] + triangle[row][col];
                    int right = prev[col] + triangle[row][col];
                    curr[col] = min (left,right); 
                }
            }
            prev = curr;
        }
        
        int res = prev[0];
        for (auto it : prev) {
            if (it<res) res = it;
        }
        
        return res;
    }
};