class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(ops[i] == "D"){
                int val = st.top();
                st.push(2*val);
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else if(ops[i] == "+"){
                int one = st.top();
                st.pop();
                int two = st.top();
                st.push(one);
                st.push((one + two));
            }
            else{
                int val = stoi(ops[i]);
                st.push(val);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};