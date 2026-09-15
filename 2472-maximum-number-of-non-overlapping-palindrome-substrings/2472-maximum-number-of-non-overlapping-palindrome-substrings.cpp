class Solution {
public:
    bool isPalin(const string&s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i];
            for(int len : {k, k+1}){
                int j = i-len+1;
                if(j>=0 && isPalin(s,j,i)){
                    dp[i+1] = max(dp[i+1], 1+dp[j]);
                }
            }
        }
        return dp[n];
    }
};