class Solution {
public:
    
    bool f (int index, int sum1, int sum2, vector<int> &nums, vector<vector<int>> &dp) {
        if (sum1 < 0) return false;
        if (sum1 == sum2) return true;
        if (index < 0) return false;
        
        if (dp[index][sum1] != -1) return dp[index][sum1];
        
        bool notTake = f(index-1, sum1, sum2, nums,dp);
        bool take = f(index-1, sum1-nums[index], sum2+nums[index], nums,dp);
        
        return dp[index][sum1] = notTake || take;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            sum += nums[i];
        }
        
        vector<vector<int>> dp (n, vector<int> (sum+1, -1));
        
        return f(n-1,sum,0,nums,dp);
    }
};