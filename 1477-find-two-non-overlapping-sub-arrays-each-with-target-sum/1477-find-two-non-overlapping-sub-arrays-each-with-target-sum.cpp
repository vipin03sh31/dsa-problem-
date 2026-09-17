class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] = min length of valid subarray ending at or before index i-1
        int ans = INT_MAX;
        int left = 0, sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            dp[right + 1] = dp[right];
            if (sum == target) {
                int len = right - left + 1;
                if (dp[left] != INT_MAX) {
                    ans = min(ans, dp[left] + len);
                }
                dp[right + 1] = min(dp[right], len);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};