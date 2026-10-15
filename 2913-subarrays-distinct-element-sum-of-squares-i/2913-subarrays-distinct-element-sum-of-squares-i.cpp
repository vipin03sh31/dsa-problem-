class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> seen(101, 0);
            int d = 0;
            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]++) d++;
                ans += d * d;
            }
        }
        return ans;
    }
};