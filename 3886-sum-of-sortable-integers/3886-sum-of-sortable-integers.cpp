class Solution {
public:
    int sortableIntegers(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            int prevMax = INT_MIN;
            for (int i = 0; i < n && ok; i += k) {
                int d = 0, mn = INT_MAX, mx = INT_MIN;
                for (int j = i; j < i + k; j++) {
                    d += a[j] > a[i + (j - i + 1) % k];
                    mn = min(mn, a[j]);
                    mx = max(mx, a[j]);
                }
                if (d > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return ans;
    }
};