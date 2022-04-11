class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int size = grid[i].size();
            for(int j=0;j<m;j++){
                ans[(i+(j+k)/m)%n][(j+k)%size] = grid[i][j];
            }
        }
        return ans;
    }
};