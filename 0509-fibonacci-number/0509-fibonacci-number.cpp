class Solution {
public:
    // top-down approach
    int slovewithdp(int n , vector<int>&dp){
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = slovewithdp(n-1,dp) + slovewithdp(n-2,dp);
        dp[n] = ans;
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans = slovewithdp(n,dp);
        return ans;
    }
};