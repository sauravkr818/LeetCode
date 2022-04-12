class Solution {
public:
    
    int getNeighbour(vector<vector<int>>& boards,int i,int j, int m, int n){
        int lives = 0;
        // up
        if(i>0){
            if(boards[i-1][j] == 1) lives++;
        }
        
        // down
        if(i+1<m){
            if(boards[i+1][j] == 1) lives++;
        }
        
        // left
        
        if(j>0){
            if(boards[i][j-1] == 1) lives++;
        }
        
        // right
        if(j+1<n){
            if(boards[i][j+1] == 1) lives++;
        }
        
        // diagonally
        
        // up-left
        if(i>0 && j>0){
            if(boards[i-1][j-1] == 1) lives++;
        }
        
        // up-right
        if(i>0 && j+1<n){
            if(boards[i-1][j+1] == 1) lives++;
        }
        
        // down-left
        if(i+1<m && j>0){
            if(boards[i+1][j-1] == 1) lives++;
        }
        
        // down-right
        if(i+1<m && j+1<n){
            if(boards[i+1][j+1] == 1) lives++;
        }
        
        return lives;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>ans = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = getNeighbour(ans,i,j,m,n);
                if(board[i][j] == 0){
                    if(count == 3){
                        board[i][j] = 1;
                    }
                }
                else{
                    if(count<2 || count>3){
                        board[i][j] = 0;
                    }
                }
                
            }
        }
        
        
    }
};