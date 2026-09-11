class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        string ans = "";
        for(int i = 0; i <s.length();i++){  // changed: start from 0
            int low = i;
            int high = i; 
            while(low >= 0 && high < s.length() && s[low] == s[high]){  // changed: bounds check first
                string palindrom = s.substr(low,high-low+1);  // changed: correct substr args
                if(palindrom.length() > ans.length()){
                    ans = palindrom;
                }
                low--;
                high++;
            }
            low = i-1;  // changed: removed 'int'
            high = i;
            while(low >= 0 && high < s.length() && s[low]== s[high]){  // changed: bounds check first
                string palindrom = s.substr(low,high-low+1);  // changed: correct substr args
                if(palindrom.length() > ans.length()){
                    ans = palindrom;
                }
                low--;
                high++;
            }


        }
        return ans;

    }
};