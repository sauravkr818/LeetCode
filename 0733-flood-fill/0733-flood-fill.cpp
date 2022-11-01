class Solution {
public:
    int val = 0;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        // base case
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;
        if(val != image[sr][sc]) return; // if image[sr][sc] != initial color
        if(image[sr][sc] == color) return; // if already colored with the new color
        
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color);
        dfs(image,sr-1,sc,color);
        dfs(image,sr,sc+1,color);
        dfs(image,sr,sc-1,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        val = image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
};