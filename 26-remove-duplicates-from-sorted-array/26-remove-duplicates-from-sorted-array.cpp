class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n<=1) return n;
        
        int flag = 0;
        
        int mini = -101;
        
        for (int i=0;i<n;i++) {
            if (nums[i] > mini ) {
                nums[flag] = nums[i];
                flag++;
                mini = nums[i];
            }
        }
        
        return flag;
    }
};