class Solution {
public:
    
    void f(int i, vector<int>&cdt, int target, vector<int>&temp, vector<vector<int>>&ans){
        // base cases
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        if(i == cdt.size()) return;
        
        
        f(i+1,cdt,target,temp,ans);
        temp.push_back(cdt[i]);
        f(i,cdt,target-cdt[i],temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,candidates,target,temp,ans);
        return ans;
    }
};