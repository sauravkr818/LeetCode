class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // {diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0] = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    //int newdiff = abs(heights[nrow][ncol] - heights[row][col]);
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]),diff);
                    if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};