class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& matrix) {
        sort(matrix.begin(),matrix.end());
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>ans = {matrix[0]};
        for(int i=1;i<m;i++){
            int val = ans.size();
            vector<int>temp = matrix[i];
            if(ans[val-1][1]>=matrix[i][0] && ans[val-1][1]>=matrix[i][1]){
                continue;
            }
            else if(ans[val-1][1]>=matrix[i][0] && ans[val-1][1]<matrix[i][1]){
                vector<int>t = {ans[val-1][0],matrix[i][1]};
                ans.pop_back();
                ans.push_back(t);
            }
            else{
                ans.push_back(temp);
            }
        }
        return ans;
    }
};