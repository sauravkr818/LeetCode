class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>st;
        for(int i=0;i<p.size();i++){
            st[p[i]]++;
        }
        vector<int>ans;
        int k = p.size();
        int i = 0, j = 0;
        int count = st.size();
        while(j<s.size()){
            
            // calculation
            
            if(st.find(s[j]) != st.end()){
                st[s[j]]--;
                if(st[s[j]] == 0){
                    count--;
                }
            }
            
            // window size < k then simply j++
            if(j-i+1<k){
                j++;
            } // window size == k means window size hit
            else if(j-i+1 == k){
                // step-1 : find ans
                if(count == 0){
                    ans.push_back(i);
                }
                // step-2 : slide window
                if(st.find(s[i]) != st.end()){
                    st[s[i]]++;
                    if(st[s[i]] == 1) count++;
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};