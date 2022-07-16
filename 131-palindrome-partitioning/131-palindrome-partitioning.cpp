class Solution {
public:
    // backtracing impt. question
    
    bool isPalindrome(int i, int j, string &s){
        string str = s.substr(i,j+1-i);
        //cout<<str<<endl;
        i = 0;
        j = str.size()-1;
        while(i<str.size()){
            if(str[i] != str[j-i]) return false;
            i++;
        }
        return true;
    }
    
    void f(int ind, string &s, vector<string>&temp, vector<vector<string>>&ans){
        // base case
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
                temp.push_back(s.substr(ind,i+1-ind));
                f(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,s,temp,ans);
        return ans;
    }
    
    
};