//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int row, int col, int n, int m, vector<vector<int>>&vis,vector<vector<char>>&mat){
        // base case
        if(row<0 || col<0 || row>n-1 || col>m-1) return;
        if(mat[row][col] == 'X') return;
        if(vis[row][col] == 1) return;
        vis[row][col] = 1;
        dfs(row+1,col,n,m,vis,mat);
        dfs(row,col+1,n,m,vis,mat);
        dfs(row-1,col,n,m,vis,mat);
        dfs(row,col-1,n,m,vis,mat);
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        //logic - check all the 'O' at the boundaries and fron them keep track of that 'O's which are reachable from them.
        // All those reachable 'O's should not be converted to X. Those who are not reachable menas they are surrounded.
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i]){
                dfs(0,i,n,m,vis,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i][m-1]){
                dfs(i,m-1,n,m,vis,mat);
            }
        }
        
        for(int i=0;i<m;i++){
            if(!vis[n-1][i]){
                dfs(n-1,i,n,m,vis,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i][0]){
                dfs(i,0,n,m,vis,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends