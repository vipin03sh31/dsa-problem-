class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        if ((m + n) % 2 == 0) return false;
        vector<bitset<202>> d(n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                bitset<202> t;
                if (!i && !j) t[0] = 1;
                else {
                    if (i) t |= d[j];
                    if (j) t |= d[j - 1];
                }
                d[j] = g[i][j] == '(' ? t << 1 : t >> 1;
            }
        return d[n - 1][0];
    }
};