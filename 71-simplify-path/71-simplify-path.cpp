class Solution {
public:
    // practise once more 
    // good question on stack
    
    string simplifyPath(string str) {
        int n = str.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            if(str[i] == '/'){
                continue;
            }
            string temp;
            while(i<str.size() && str[i] != '/'){
                
                temp += str[i];
                i++;
            }
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(st.empty() == false){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        string ans;
        while(st.empty() == false){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(ans.size() == 0) return "/";
        
        return ans;
    }
};