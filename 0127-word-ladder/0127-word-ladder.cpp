class Solution {
public:
    int ladderLength(string startword, string targetword, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startword,1});
        st.erase(startword);
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int seq = it.second;
            if(word == targetword) return seq;
            
            // T.C. - (N *  O(word length * 26)) = N because N words are there in the queue at the wost
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word,seq+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};