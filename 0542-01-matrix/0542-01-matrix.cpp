class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0)), dist(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>>q; // {{i,j},step}
        // initial step of all zeroes is 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0)
                q.push({{i,j},0});
            }
        }
        
        int deltarow[] = {-1,0,1,0};
        int deltacol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[row][col] = step;
            vis[row][col] = 1;
            for(int i=0;i<4;i++){
                int newrow = row + deltarow[i];
                int newcol = col + deltacol[i];
                if(newrow>=0 && newcol>=0 && newrow<m && newcol<n && vis[newrow][newcol] == 0 && mat[newrow][newcol] == 1){
                    vis[newrow][newcol] = 1;
                    q.push({{newrow,newcol},step+1});
                }
            }
        }
        return dist;
    }
};