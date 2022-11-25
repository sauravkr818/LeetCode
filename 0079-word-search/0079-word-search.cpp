class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        // base case
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        
        if(board[i][j] != word[idx]) return false;
        
        // mark as visited  // backtracing first step
        board[i][j] = '*';
        // four direction
        bool four_direction = dfs(board,word,i+1,j,idx+1) ||
                              dfs(board,word,i-1,j,idx+1) ||
                              dfs(board,word,i,j+1,idx+1) ||
                              dfs(board,word,i,j-1,idx+1);
        // backtracing second step
        board[i][j] = word[idx];
        return four_direction;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        // plain dfs + bracktrack
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
    
    
};