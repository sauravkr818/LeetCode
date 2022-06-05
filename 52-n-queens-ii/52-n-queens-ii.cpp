class Solution {
public:
    
    
    //int ans = 0;
    
    
    bool isSafe(int row, int col, int n, vector<string>board){
        int duprow = row, dupcol = col;
        
        
        // left-up diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;col--;
        }
        row = duprow;
        col = dupcol;
        // left-side
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = dupcol;
        // left-down
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;col--;
        }
        return true;
    }
    
    void f(int col,int n, vector<string>&board, vector<vector<string>>&ans){
        // base case
        if(col == n){
            ans.push_back(board);
            
        }
        
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                f(col+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        f(0,n,board,ans);
        return ans.size();
    }
};