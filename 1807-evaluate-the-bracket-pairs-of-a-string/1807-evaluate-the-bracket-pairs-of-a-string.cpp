class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge) mp[k[0]] = k[1];

        string res;
        int n = s.size(), i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') j++;
                string key = s.substr(i + 1, j - i - 1);
                res += mp.count(key) ? mp[key] : "?";
                i = j + 1;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};