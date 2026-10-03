class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }
        int maxlenght = 0;              // FIX: start at 0, not INT_MIN
        stack<int> st;
        st.push(-1);                    // FIX: sentinel base index

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);          // this ')' becomes the new base
                } else {
                    maxlenght = max(maxlenght, i - st.top());
                }
            }
        }

        return maxlenght;
    }
};