//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginword, string endword, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginword});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginword);
        int level = 0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>temp = q.front();
            q.pop();
            // erase all the words that has been used in the previous level to transform
            if(temp.size()>level){ // newer level condition and erase usedOnLevel strings from the set
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                
            }
            
            string word = temp.back();
            
            
            if(word == endword){
                // the first sequence where we reached the end
                if(ans.size() == 0){
                    ans.push_back(temp);
                }
                else if(ans[0].size() == temp.size()){
                    ans.push_back(temp);
                }
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        // insert word and then pop_back because there can be many possibilities
                        temp.push_back(word);
                        q.push(temp);
                        // mark this as visited on the level so as to erase it from the set on next level
                        usedOnLevel.push_back(word);
                        temp.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends