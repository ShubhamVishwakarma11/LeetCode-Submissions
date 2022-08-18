class Solution {
public:
    
    int f (int index, int &mini, vector<int> &dp, vector<int>& prices) {
        if (index == 0) {
            mini = prices[0];
            return 0;
        }
        if (dp[index] != -1) return dp[index];
        int price = f(index-1,mini,dp,prices);
        mini = min (mini, prices[index]);
        return dp[index] = max(price, prices[index]-mini);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp (n , -1);
        int mini = INT_MAX;
        return f(n-1,mini,dp,prices);
    }
};