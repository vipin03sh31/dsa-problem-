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
    // int sloveusingrec(int n, int k, int target, vector<vector<long long
    // int>>& dp) {
    //     if (n < 0 || target < 0) {
    //         return 0;
    //     }
    //     if (n == 0 && target == 0) {
    //         return 1;
    //     }
    //     if (n == 0 && target != 0) {
    //         return 0;
    //     }
    //     if (n != 0 && target == 0) {
    //         return 0;
    //     }
    //     if(dp[n][target] != -1){
    //         return dp[n][target];
    //     }
    //     long long int ans = 0;
    //     for (int val = 1; val <= k; val++) {
    //         ans = (ans%MOD + sloveusingrec(n - 1, k, target - val,
    //         dp)%MOD)%MOD;
    //     }
    //     dp[n][target] = ans;
    //     return ans;
    // }
    // tabulation
    // bottom -up
    int sloveusingdp2(int n, int k, int target) {
        vector<vector<long long int>> dp(n + 1,
                                         vector<long long int>(target + 1, 0));
        dp[0][0] = 1;
        for (int a = 1; a <= n; a++) {
            for (int t = 1; t <= target; t++) {
                long long int ans = 0;
                for (int val = 1; val <= k; val++) {
                    long long temp = 0;
                    if(t-val >= 0){
                        temp = dp[a-1][t-val] % MOD;
                    }
                    ans = (ans % MOD + temp) %MOD;
                }
                dp[a][t] = ans;
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<long long int>> dp(n + 1, vector<long long int>(target
        // + 1, -1));
        int ans = sloveusingdp2(n, k, target);
        return ans;
    }
};