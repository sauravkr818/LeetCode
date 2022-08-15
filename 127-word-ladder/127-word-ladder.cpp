class Solution {
public:
    // https://www.youtube.com/watch?v=ZVJ3asMoZ18&ab_channel=TECHDOSE
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        bool isEndWordPresent = false;
        for(auto word: wordList){
            if(endWord == word){
                isEndWordPresent = true;
            }
            st.insert(word);
        }
        if(!isEndWordPresent) return 0;
        queue<string>q;
        q.push(beginWord);
        int depth = 0;
        int level = q.size();
        bool went = false;
        while(q.empty() == false){
            depth += 1;
            level = q.size();
            while(level--){
                string temp = q.front();q.pop();
                for(int i=0;i<temp.size();i++){
                    string temp2 = temp;
                    for(char c='a'; c<='z';c++){
                        temp2[i] = c;
                        if(temp.compare(temp2) == 0){
                            continue; // skip the same word
                        }
                        if(temp2.compare(endWord) == 0){
                            went = true;
                            return depth+1; // endWord found
                        }
                        if(st.find(temp2) != st.end()){
                            q.push(temp2);
                            st.erase(temp2);
                            
                        }
                    }
                }
            }
        }
        if(!went) return 0;
        return depth+1;
        
    }
};