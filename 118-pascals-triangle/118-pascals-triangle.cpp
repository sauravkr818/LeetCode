class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        vector<int>one = {1};
        ans.push_back(one);
        if(n == 1) return ans;
        vector<int>two = {1,1};
        ans.push_back(two);
        if(n == 2) return ans;
        vector<int>three = {1,2,1};
        ans.push_back(three);
        if(n == 3) return ans;
        n = 3;
        while(n != numRows){
            vector<int>temp;
            vector<int>save = ans[n-1];
            temp.push_back(1);
            for(int i=1;i<n;i++){
                temp.push_back(save[i]+save[i-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            n++;
        }
        return ans;
    }
};