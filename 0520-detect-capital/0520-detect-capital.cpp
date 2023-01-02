class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        if((word[0]>=65 && word[0] <= 90) && (word[1]>=65 && word[1] <= 90) ){
            for(int i=2;i<n;i++){
                if(word[i]>90) return false;
            }
            return true;
        }
        else if((word[0]>=65 && word[0] <= 90) && (word[1]>90)){
            for(int i=2;i<n;i++){
                if(word[i]<=90) return false;
            }
            return true;
        }
        else{
            for(int i=0;i<n;i++){
                if(word[i]<=90) return false;
            }
            return true;
        }
        return true;
    }
};