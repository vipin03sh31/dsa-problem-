class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return intervals[a][1] < intervals[b][1];
        });

        vector<int> endArr(n);
        for (int i = 0; i < n; i++) endArr[i] = intervals[order[i]][1];

        // dp[i][k] = best (score, sorted indices) using first i sorted intervals, at most k chosen
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5, {0, {}})
        );

        auto better = [](const pair<long long, vector<int>>& a,
                          const pair<long long, vector<int>>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };

        for (int i = 1; i <= n; i++) {
            int origIdx = order[i - 1];
            int l = intervals[origIdx][0];
            int w = intervals[origIdx][2];

            int cnt = lower_bound(endArr.begin(), endArr.begin() + (i - 1), l) - endArr.begin();

            for (int k = 0; k <= 4; k++) {
                pair<long long, vector<int>> best = dp[i - 1][k]; // skip current

                if (k >= 1) {
                    pair<long long, vector<int>> cand = dp[cnt][k - 1];
                    cand.first += w;
                    auto pos = upper_bound(cand.second.begin(), cand.second.end(), origIdx);
                    cand.second.insert(pos, origIdx);
                    if (better(cand, best)) best = cand;
                }
                dp[i][k] = best;
            }
        }

        return dp[n][4].second;
    }
};