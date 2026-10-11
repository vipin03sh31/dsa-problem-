class Solution {
public:
long long int MOD = 1000000007;
    // int sloveusingrec(int n, int k, int target) {
    //     if ( n <0 || target <0){
    //         return 0;
    //     }
    //     if(n == 0 && target == 0){
    //         return 1;
    //     }
    //     if(n == 0 && target != 0){
    //         return 0;
    //     }
    //     if(n != 0 && target == 0){
    //         return 0;
    //     }
    //     int ans = 0;
    //     for (int val = 1; val <= k; val++) {
    //         ans = ans + sloveusingrec(n-1, k, target-val);
    //     }
    //     return ans;
    // }
    // top-down 2d
    int sloveusingrec(int n, int k, int target, vector<vector<long long int>>& dp) {
        if (n < 0 || target < 0) {
            return 0;
        }
        if (n == 0 && target == 0) {
            return 1;
        }
        if (n == 0 && target != 0) {
            return 0;
        }
        if (n != 0 && target == 0) {
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        long long int ans = 0;
        for (int val = 1; val <= k; val++) {
            ans = (ans%MOD + sloveusingrec(n - 1, k, target - val, dp)%MOD)%MOD;
        }
        dp[n][target] = ans;
        return ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
        int ans = sloveusingrec(n, k, target, dp);
        return ans;
    }
};