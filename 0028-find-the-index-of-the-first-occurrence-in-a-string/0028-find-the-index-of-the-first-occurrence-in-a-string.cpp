class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        if(n > m){
            return -1;
        }
        for(int i = 0;i<=m-n;i++){
            string t = haystack.substr(i,n);
            if(t == needle){
                return i;
            }
        }
        return -1;
        
    }
};