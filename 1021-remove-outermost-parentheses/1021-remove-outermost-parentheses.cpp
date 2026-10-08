class Solution {
public:
    string removeOuterParentheses(string s) {
        string r;
        int d = 0;
        for (char c : s) {
            if (c == '(' && d++ > 0) r += c;
            if (c == ')' && --d > 0) r += c;
        }
        return r;
    }
};