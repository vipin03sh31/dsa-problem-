class Solution {
public:
    // int sloveusingrec(vector<int>& nums,int index){
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     int include = nums[index]+ sloveusingrec(nums,index+2);
    //     int exclude = 0 + sloveusingrec(nums,index+1);
    //     int ans = max(include,exclude);
    //     return ans;
    // }
    //1D DP
    // top-down solution
    int sloveusingdp(vector<int>& nums,int index,vector<int>&dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index]+ sloveusingdp(nums,index+2,dp);
        int exclude = 0 + sloveusingdp(nums,index+1,dp);
        int ans = max(include,exclude);
        dp[index] = ans;
        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int index = 0;
        int ans = sloveusingdp(nums,index,dp);
        return ans;
        
    }
};