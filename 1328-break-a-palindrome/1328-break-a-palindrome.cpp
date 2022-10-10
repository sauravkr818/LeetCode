class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1) return "";
        int i=0,j=n-1;
        bool temp = false;
        while(i<=j){
            if(s[i] != 'a' && i != j){
                s[i] = 'a';
                temp = true;
                break;
            }
            i++;
            j--;
        }
        
        if(temp == false){
            s[n-1] = 'b';
        }
        return s;
    }
};