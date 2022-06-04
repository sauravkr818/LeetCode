class Solution {
public:
    
    bool isSafe(int row, int col,int n, vector<string>board){
        
        // inorder to check whether placing a queen at index [row][col] is safe or not  we should know 
        // these facts:
        // 1. Every col has exactly one queen and every row has exactly one queen.
        // 2. You are traversing from col = 0 hence it is not necessary to check for right-diagonals and right side
        // 3. You are only required to check the left-diagonals and left side
        // 4. Also since you are travelling from row=0 to row = n-1 and you know only one queen is to be placed in a column hence you need not check up and down direction as well
        // 5. therefore directions to travel
        
     
        //          \
        //           \
        //            \
        //       <----- [row][col]
        //            /
        //           /
        //          /
        
        
        // hence you must check in only these directions
        
        // ------------ checking left-up diagonal --------------
        
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0){
            
            if( board[row][col] == 'Q') return false;
            row--;col--;
        }
        
        // --------------- checking left -------------------
        
        row = duprow;
        col = dupcol;
        while(col>=0){
            
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        // ------------ checking left-down diagonal --------------
        
        col = dupcol;
        while(row<n && col>=0){
            
            if(board[row][col] == 'Q') return false;
            row++;col--;
        }
        
        return true;
        
        
    }
    
    void solve(int col, int n, vector<string>&board,vector<vector<string>>&ans)
    {
        // base case
        if(col == n){
            ans.push_back(board);
        }
        
        // for every column col, we will be checking each row whether we can insert the queen or not.
        for(int row = 0; row<n; row++){
            if(isSafe(row,col,n,board)){
                // backtracking
                
                // insert the queen 
                board[row][col] = 'Q';
                solve(col+1,n,board,ans);
                // take out the queen
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board; // n*n board with all boxes as '.' initially.
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0,n,board,ans);
        return ans;
    }
};