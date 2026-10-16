class Solution {
public:
    int ms(vector<int>& a, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        int c = ms(a, l, m) + ms(a, m + 1, r);
        for (int i = l, j = m + 1; i <= m; i++) {
            while (j <= r && a[i] > 2LL * a[j]) j++;
            c += j - (m + 1);
        }
        inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1);
        return c;
    }
    int reversePairs(vector<int>& nums) {
        return ms(nums, 0, nums.size() - 1);
    }
};