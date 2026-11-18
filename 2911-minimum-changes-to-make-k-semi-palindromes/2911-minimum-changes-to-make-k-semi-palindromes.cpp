class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> c(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int l = j - i + 1;
                for (int d = 1; d < l; d++) {
                    if (l % d) continue;
                    int t = 0;
                    for (int r = 0; r < d; r++)
                        for (int a = i + r, b = j - d + 1 + r; a < b; a += d, b -= d)
                            t += s[a] != s[b];
                    c[i][j] = min(c[i][j], t);
                }
            }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int j = 1; j <= k; j++)
            for (int i = 1; i <= n; i++)
                for (int p = 0; p <= i - 2; p++)
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + c[p][i - 1]);
        return dp[n][k];
    }
};