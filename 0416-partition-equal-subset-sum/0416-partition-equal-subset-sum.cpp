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
    //     int include = sloveusingRec(index+1,nums,target-nums[index]);
    //     int exclude = sloveusingRec(index+1,nums,target);

    //     return (include||exclude);
    // }
    // slove using momoisation
    bool sloveusingDP(int index, vector<int>& nums, int target,
                      vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        int include = sloveusingDP(index + 1, nums, target - nums[index], dp);
        int exclude = sloveusingDP(index + 1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
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
        bool ans = sloveusingDP(index, nums, target, dp);
        return ans;
    }
};