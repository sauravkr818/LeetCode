class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int n = token.size();
        if(n == 0) return 0;
        //if(n == 1 && power>=token[0]) return 1;
        sort(token.begin(),token.end());
        if(token[0] > power) return 0;
        
        int score = 0;
        int i=0,j=n-1;
        int maxi_score = 0;
        while(i<=j){
            if(score == 0){
                if(power>= token[i]){
                    power -= token[i];
                    score++;
                }
                i++;
            }
            else if(score>0){
                if(power>=token[i]){
                    score++;
                    power -= token[i];
                    i++;
                }
                else if(power<token[i]){
                    power += token[j];
                    j--;
                    score -= 1;
                }
            }
            //cout<<score<<endl;
            maxi_score = max(maxi_score,score);
        }
        return maxi_score;
        
    }
};