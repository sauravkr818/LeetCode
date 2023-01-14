//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    vector<int>delrow = {-1,0,1,0};
    vector<int>delcol = {0,1,0,-1};
    void dfs(vector<vector<int>>& img, int row, int col, int newColor,int initColor,vector<vector<int>>& ans) {
        ans[row][col] = newColor;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<img.size() && ncol>=0 && 
            ncol<img[0].size() && img[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                
                dfs(img,nrow,ncol,newColor,initColor,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int newColor) {
        // Code here
        int initColor = img[sr][sc];
        //img[sr][sc] = newColor;
        vector<vector<int>>ans = img;
        dfs(img,sr,sc,newColor,initColor,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends