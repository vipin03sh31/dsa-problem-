class Solution {
public:
    // bool sloveusingRec(int index,vector<int>&nums,int target){
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     if(target < 0){
    //         return 0;
    //     }
    //     if(target == 0){
    //         return 1;
    //     }
    //     bool include = sloveusingRec(index+1,nums,target-nums[index]);
    //     bool exclude = sloveusingRec(index+1,nums,target);

    //     return (include||exclude);
    // }
    // slove using momoisation
    // top- down
    // bool sloveusingDP(int index, vector<int>& nums, int target,
    //                   vector<vector<int>>& dp) {
    //     if (index >= nums.size()) {
    //         return 0;
    //     }
    //     if (target < 0) {
    //         return 0;
    //     }
    //     if (target == 0) {
    //         return 1;
    //     }
    //     if(dp[index][target] != -1){
    //         return dp[index][target];
    //     }
    //     bool include = sloveusingDP(index + 1, nums, target - nums[index],
    //     dp); bool exclude = sloveusingDP(index + 1, nums, target, dp);

    //     dp[index][target] = (include || exclude);
    //     return dp[index][target];
    // }
    // bottom up
    bool sloveusingDP2( vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 1; t <= target; t++) {
                bool include = 0;
                if(t - nums[i] >= 0){
                    include = dp[i + 1][t - nums[i]];
                }
                bool exclude = dp[i + 1][t];

                dp[i][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        if (totalSum & 1) {
            return false;
        }
        int target = totalSum / 2;
        int index = 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        bool ans = sloveusingDP2(nums, target);
        return ans;
    }
};