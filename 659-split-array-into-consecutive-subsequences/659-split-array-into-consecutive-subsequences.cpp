class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>fmp; // frequency map
        unordered_map<int,int>hmp; // hypothetical map
        for(int i: nums){
            fmp[i]++;
        }
        for(int i=0;i<n;i++){
            int t = nums[i];
            if(fmp[t] == 0) continue;
            if(hmp[t] > 0){
                hmp[t]--;
                fmp[t]--;
                
                hmp[t+1]++;
            }
            else if(fmp[t] > 0 && fmp[t+1] > 0 && fmp[t+2] > 0){
                fmp[t]--;
                fmp[t+1]--;
                fmp[t+2]--;
                hmp[t+3]++;
            }
            else return false;
        }
        return true;
    }
};