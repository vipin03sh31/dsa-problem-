class Solution {
public:
    // int sloveusingRec(int n){
    //     if( n == 0){
    //         return 0;
    //     }
    //     int ans = INT_MAX;
    //     for(int i = 1; i*i<= n;i++){
    //         int count = 1 + sloveusingRec(n - i*i);
    //         ans = min(ans, count);
    //     }
    //     return ans;
    // }

    int sloveusingDP(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int count = 1 + sloveusingDP(n - i * i, dp);
            ans = min(ans, count);
        }
        dp[n] = ans;
        return dp[n];
    }
    int sloveusingDP2(int n) {
        vector<int> dp(n + 1, INT_MAX);                    // changed
        dp[0] = 0;                                         // changed
        for (int i = 1; i <= n; i++) {                     // changed
            for (int j = 1; j * j <= i; j++) {             // changed
                dp[i] = min(dp[i], 1 + dp[i - j * j]);     // changed
            }
        }
        return dp[n];                                      // changed
    }
    int numSquares(int n) {
        // Placeholder logic for finding the least number of perfect squares
        // vector<int>dp(n+1,-1);
        int ans = sloveusingDP2(n);
        return ans;
    }
};