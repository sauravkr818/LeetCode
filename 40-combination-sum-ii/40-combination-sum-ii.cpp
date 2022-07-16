class Solution {
public:
    
    void f(int i, vector<int>&cdt, int target, vector<int>&temp, vector<vector<int>>&ans){
        // base cases
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        //if(i == cdt.size()) return;
        
        for(int ind = i;ind<cdt.size();ind++){
            if(ind>i && cdt[ind] == cdt[ind-1]) continue;
            //f(ind+1,cdt,target,temp,ans);
            temp.push_back(cdt[ind]);
            f(ind+1,cdt,target-cdt[ind],temp,ans);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,candidates,target,temp,ans);
        return ans;
    }
};