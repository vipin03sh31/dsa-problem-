class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if (i >= days.size()) return 0;
        if (dp[i] != -1) return dp[i];                          // changed

        int oneDay = costs[0] + solve(days, costs, i + 1, dp);  // changed

        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int sevenDay = costs[1] + solve(days, costs, j, dp);    // changed

        while (j < days.size() && days[j] < days[i] + 30) j++;
        int thirtyDay = costs[2] + solve(days, costs, j, dp);   // changed

        return dp[i] = min(oneDay, min(sevenDay, thirtyDay));   // changed
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);                        // changed
        return solve(days, costs, 0, dp);                       // changed
    }
};