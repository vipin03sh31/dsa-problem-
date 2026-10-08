class Solution {
public:
    // int sloveusingrec(vector<int>& nums,int curr,int prev){
    //     if(curr >= nums.size()){
    //         return 0;
    //     }

    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         include = 1+sloveusingrec(nums,curr+1,curr);

    //     }
    //     int exclude = 0+sloveusingrec(nums,curr+1,prev);
    //     int finalans = max(include,exclude);
    //     return finalans;

    // }
    // 2D dp
    // top-down approach
    int sloveusingdp(vector<int>& nums, int curr, int prev,vector<vector<int>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][curr];
        }

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + sloveusingdp(nums, curr + 1, curr,dp);
        }
        int exclude = 0 + sloveusingdp(nums, curr + 1, prev,dp);
        int finalans = max(include, exclude);
        dp[curr][prev+1] = finalans;
        return finalans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
        int prev = -1;
        int curr = 0;

        int ans = sloveusingdp(nums, curr, prev,dp);
        return ans;
    }
};