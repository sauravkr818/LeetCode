class Solution {
public:
    
    
    vector<string>s = {"a","e","i","o","u"};
    
    
    void permute(string &temp,int n, vector<string>&ans,int t){
        // base cases
        
        
        if(temp.size()>n){
            return; 
        }
        if(temp.size() == n){
            ans.push_back(temp);
            t += 1;
            //cout<<temp<<" ";
            return;
        }
        
        
        for(int i=t;i<=4;i++){
            temp += (s[i]);
            permute(temp,n,ans,i);
            temp.pop_back();
        }
    }
    
    int countVowelStrings(int n) {
        vector<string>ans;
        string temp;
        permute(temp,n,ans,0);
        return ans.size();
    }
};