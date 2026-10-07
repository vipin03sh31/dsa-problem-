class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') l ? l-- : r++;
        }
        vector<string> res;
        string cur;
        function<void(int, int, int, int)> dfs = [&](int i, int l, int r, int open) {
            if (l < 0 || r < 0 || open < 0) return;
            if (i == s.size()) {
                if (!l && !r && !open) res.push_back(cur);
                return;
            }
            char c = s[i];
            if (c != '(' && c != ')') {
                cur.push_back(c);
                dfs(i + 1, l, r, open);
                cur.pop_back();
                return;
            }
            int j = i;
            while (j < s.size() && s[j] == c) j++;
            int k = j - i;
            for (int t = 0; t <= k; t++) {
                int kept = k - t;
                cur.append(kept, c);
                if (c == '(') dfs(j, l - t, r, open + kept);
                else dfs(j, l, r - t, open - kept);
                cur.resize(cur.size() - kept);
            }
        };
        dfs(0, l, r, 0);
        return res;
    }
};