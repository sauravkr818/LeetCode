class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},0}); // {{row,col},steps}
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;
            
            for(int i=0;i<4;i++){
                int newr = row + delrow[i];
                int newc = col + delcol[i];
                
                if(newr>=0 && newc>=0 && newr<n && newc<m && maze[newr][newc] == '.'){
                    // if found an exit
                    if(newr == 0 || newc == 0 || newr == n-1 || newc == m-1){
                        return steps + 1;
                    }
                    
                    // else mark this as visited
                    maze[newr][newc] = '+';
                    q.push({{newr,newc},steps+1});
                    
                }
                
            }
        }
        return -1;
    }
};