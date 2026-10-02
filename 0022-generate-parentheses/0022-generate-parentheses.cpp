class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        function<void(int,int)> go = [&](int o, int c) {
            if (s.size() == 2 * n) { res.push_back(s); return; }
            if (o < n) { s += '('; go(o + 1, c); s.pop_back(); }
            if (c < o) { s += ')'; go(o, c + 1); s.pop_back(); }
        };
        go(0, 0);
        return res;
    }
};