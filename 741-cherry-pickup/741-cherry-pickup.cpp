class Solution {
public:
    static const int n1 = 50;
    int dp[50][50][50];
    
    int f(int i1, int j1, int i2, int j2, vector<vector<int>>&grid){
        // base cases
        // (i) out of bound cases
        if(i1< 0 || i2<0 || j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size() || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e8;
        
        // (ii) destination
        if(i1 == 0 && j1 == 0) return grid[i1][j1];
        
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];

        
        int maxi = 0;
        
        if(i1 == i2 && j1 == j2) maxi += grid[i1][j1];
        else maxi += grid[i1][j1]+grid[i2][j2];
        
        int up = f(i1-1,j1,i2-1,j2,grid);
        int up_left = f(i1-1,j1,i2,j2-1,grid);
        int up_left_i1 = f(i1,j1-1,i2-1,j2,grid);
        int left = f(i1,j1-1,i2,j2-1,grid);
        
        maxi += max(max(up,up_left), max(up_left_i1,left));
        dp[i1][j1][i2] = maxi;
        return maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,f(n-1,n-1,n-1,n-1,grid));
        
    }
};