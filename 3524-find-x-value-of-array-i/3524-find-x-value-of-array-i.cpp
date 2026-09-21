class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);
        for (int x : nums) {
            int m = x % k;
            vector<long long> newCnt(k, 0);
            for (int v = 0; v < k; v++) {
                if (cnt[v]) newCnt[(v * m) % k] += cnt[v];
            }
            newCnt[m] += 1;
            cnt = newCnt;
            for (int v = 0; v < k; v++) result[v] += cnt[v];
        }
        return result;
    }
};
