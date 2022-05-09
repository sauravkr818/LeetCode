class Solution {
public:
    
    unordered_map<char,string> mp;
        
    
    vector<string>ans;
    
    void permute(string &digits, int i, string &combination){
        
        if(i == digits.size()){
            ans.push_back(combination);
            return;
        }
        
        for(auto c: mp[digits[i]]){
            combination += (c);
            permute(digits,i+1,combination);
            combination.pop_back();
        }
    }
    
    
    
    vector<string> letterCombinations(string digits) {
      
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        if(digits == ""){
            return ans;
        }
        
        string combination = "";
        permute(digits,0,combination);
        return ans;
        
    }
};