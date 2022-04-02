class Solution {
public:
    bool validPalindrome(string s) {
        int a = 0;
        int b = s.size()-1;
        string temp = s;
        int count = 0;\
        int m = 0;
        while(a<=b){
            if(s[a] != s[b]){
                count++;
                if(count == 2) m = 1;
                b--;
            }
            else{
                a++;
                b--;
            }
        }
        a = 0;
        b = temp.size()-1;
        count = 0;
        int n = 0;
        while(a<=b){
            if(s[a] != s[b]){
                count++;
                if(count == 2) n = 1;
                a++;
            }
            else{
                a++;
                b--;
            }
        }
        if(m == 1 && n == 1) return false;
        else return true;
    }
};