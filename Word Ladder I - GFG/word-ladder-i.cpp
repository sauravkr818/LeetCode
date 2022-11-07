//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int step = it.second;
            if(word == targetWord) return step;
            // for every character of word I am making a change hence run a loop till word.size()
            for(int i=0;i<word.size();i++){
                char original = word[i]; // this is the character I am looking to change
                for(char ch='a';ch<='z';ch++){
                    // I will replace word[i] to every character from 'a' to 'z' and 
                    // check whether it exist on the set or not
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        // tell the set that you have visited this word
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original; // changing back the word[i] to original
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends