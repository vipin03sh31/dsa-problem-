class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char>st;
        for(int i = 0; i <  s.length();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else{ 
                //ch == ')'
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                }
            }
        }

        if(!st.empty()){
            count = count + st.size();
        }
        return count;
        
        
    }
};