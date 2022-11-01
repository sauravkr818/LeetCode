class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        int cntFrsh = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
                
                if(grid[i][j] == 1) cntFrsh++;
            }
            
        }
        int cnt = 0;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
            
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
        //     }}
        if(cnt != cntFrsh) return -1;
        return tm;
    }
};