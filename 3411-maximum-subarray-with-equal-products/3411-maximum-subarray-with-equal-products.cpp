class Solution {
public:
    int maxLength(vector<int>& nums) {
        int r = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            long long p = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (p > 25200) break;
                if (p == l * g) r = max(r, j - i + 1);
            }
        }
        return r;
    }
};