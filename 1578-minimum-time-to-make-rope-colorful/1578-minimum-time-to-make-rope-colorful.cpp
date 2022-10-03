class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int sum = neededTime[0];
        int maxi = neededTime[0];
        for(int i=1;i<=colors.size();i++){
            if(i<colors.size() && colors[i] == colors[i-1]){
                if(sum == 0){
                    sum += neededTime[i-1];
                }
                sum += neededTime[i];
                int temp = max(neededTime[i],neededTime[i-1]);
                maxi = max(maxi,temp);
            }
            else{
                ans += sum - maxi;
                sum = 0;
                maxi = 0;
            }
        }
        return ans;
    }
};