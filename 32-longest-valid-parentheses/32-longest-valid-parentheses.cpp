class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        int length = 0;
        int max_length = 0;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                st.pop();
                if(st.empty() == false)
                length = i-st.top();
                else st.push(i);
            }
            max_length = max(length,max_length);
        }
        return max_length;
    }
};