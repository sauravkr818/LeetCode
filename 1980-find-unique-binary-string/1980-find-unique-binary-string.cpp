class Solution {
public:
    string ans = "";
    void f(int i, string &res,int n,unordered_set<string>s,int &a){
        if(i == n){
            if(s.find(res) == s.end()){
                a = 1;
                ans = res;
            }
            return;
        }
        if(i != n){
            res.push_back('0');
            f(i+1,res,n,s,a);
            res.pop_back();
        }
        if(a == 1) return;
        if(a == 0){
            res.push_back('1');
            f(i+1,res,n,s,a);
            res.pop_back();
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        string res = "";
        int a = 0;
        f(0,res,n,s,a);
        return ans;
    }
};