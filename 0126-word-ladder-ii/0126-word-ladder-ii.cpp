class Solution {
    vector<vector<string>>ans;
    unordered_map<string,int>mpp;
    string begin;
    int sizee;
private:
    void dfs(string word, vector<string>&seq){
        // base case
        if(word == begin){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int val = mpp[word];
        
        for(int i=0;i<sizee;i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word]+1 == val){ // important step
                    // Ony enter when the next word is 1 step less than current word
                    // --------------------
                    // now backtrack
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                    // ---------------------
                }
            }
            word[i] = original;
        }
        
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        begin = beginWord;
        sizee = beginWord.size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        // erase the word from the set
        st.erase(beginWord);
        int sz = beginWord.size();
        mpp[beginWord] = 1;
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            if(word == endWord) break;
            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        mpp[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        // if you find the last word
        if(mpp.find(endWord) != mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};