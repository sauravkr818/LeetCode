class Solution {
public:
    string reverseStr(string s, int k) {
        int i,j;
        for(int m=0;m<s.size();m+=2*k){
            i = m, j = i+k-1;
            if(i>=s.size()) break;
            if(j>=s.size()){
                j = s.size()-1;
            }
            while(i<=j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};