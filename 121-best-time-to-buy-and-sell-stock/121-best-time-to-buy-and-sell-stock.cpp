class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0;
        int mini = INT_MAX;
        
        for (int i=0;i<n;i++) {
            mini = min (mini, prices[i]);
            int currP = prices[i] - mini;
            maxP = max(maxP, currP);
        }
        
        return maxP;
    }
};