class Solution {
public:
    string reverseWords(string s) {
        int lastIdx = -1;
        int n = s.size();
        for(int m=0;m<=n;m++){
            if(m == n || s[m] == ' '){
                int i = lastIdx+1;
                int j = m-1;
                while(i<j){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                lastIdx = m;
            }
        }
        return s;
    }
};