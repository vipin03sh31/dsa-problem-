class Solution {
public:
    int minOperations(string s) {
        string t = s;
    sort(t.begin(), t.end());
    int n = s.size();
    if (s == t) return 0;
    if (n == 2) return -1;
    if (s[0] == t[0] || s[n-1] == t[n-1]) return 1;
    if (s[0] == t[n-1] && s[n-1] == t[0] && count(s.begin(), s.end(), t[0]) == 1 && count(s.begin(), s.end(), t[n-1]) == 1) return 3;
    return 2;
        
    }
};