class Solution {
public:
    
    int DFS(vector<vector<int>>& grid, int i, int j) {
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        // return if current position is of water or is already visited
        if(grid[i][j] == 0)
            return 0;
        
        // mark the current as visited
        grid[i][j] = 0;
        
        // do DFS in all 4 directions
        return 1 + DFS(grid, i+1, j) +
        DFS(grid, i, j-1) +
        DFS(grid, i-1, j) +
        DFS(grid, i, j+1);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == 1) {
                    islands = max(islands,DFS(grid, i, j));
                } 
            }
        }
        return islands;
        
    }
};