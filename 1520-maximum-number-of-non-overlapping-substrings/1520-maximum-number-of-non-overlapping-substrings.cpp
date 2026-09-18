class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        vector<pair<int,int>> intervals; // (start, end)
        
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int start = first[c], end = last[c];
            bool valid = true;
            int i = start;
            while (i <= end) {
                int ch = s[i] - 'a';
                if (first[ch] < start) { valid = false; break; }
                end = max(end, last[ch]);
                i++;
            }
            if (valid) intervals.push_back({start, end});
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        vector<string> ans;
        int lastEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > lastEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }
        
        return ans;
    }
};