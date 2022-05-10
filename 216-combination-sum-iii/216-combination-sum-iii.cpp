class Solution {
public:
    vector<vector<int>>ans;
    
    void permute(vector<int>&temp,int t, int k, int n){
        // base cases
        if(n<0 || temp.size()>k){
            return; 
        }
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=t;i<=9;i++){
            temp.push_back(i);
            permute(temp,i+1,k,n-i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<vector<int>>ans;
        vector<int>temp;
        permute(temp,1,k,n);
        return ans;
    }
};