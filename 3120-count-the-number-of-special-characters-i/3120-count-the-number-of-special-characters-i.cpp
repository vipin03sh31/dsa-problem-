class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st(word.begin(), word.end());
    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c++)
        if (st.count(c) && st.count(c - 32)) cnt++;
    return cnt;
        



        
    }
};