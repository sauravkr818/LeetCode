/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int hd = 0;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>m;
        while(q.empty() == false){
            auto temp = q.front();
            q.pop();
            TreeNode* p = temp.first;
            int x = temp.second.first, y = temp.second.second;
            
            m[x][y].insert(p->val);
            if(p->left){
                q.push({p->left,{x-1,y+1}});
            }
            if(p->right){
                q.push({p->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it : m){
            vector<int>arr_vertical;
            for(auto q: it.second){
                arr_vertical.insert(arr_vertical.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(arr_vertical);
        }
        return ans;
    }
};