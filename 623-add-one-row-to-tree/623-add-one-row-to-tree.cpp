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
    
    void f(TreeNode* root, int depth, vector<TreeNode*>&ans){
        if(!root) return;
        // cout<<depth<<endl;
        if(depth == 0){
            ans.push_back(root);
        }
        f(root->left,depth-1,ans);
        f(root->right,depth-1,ans);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //return root;
        if(depth == 1){
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        vector<TreeNode*> ans;
        f(root,depth-2,ans);
        // for(auto t: ans){
        //     cout<<t->val<<" ";
        // }
        for(int i=0;i<ans.size();i++){
            TreeNode*one = ans[i];
            TreeNode*three = one->left, *four = one->right;
            TreeNode* temp = one;
            one->left = new TreeNode(val);
            one = one->left;
            one->left = three;
            temp->right = new TreeNode(val);
            temp = temp->right;
            temp->right = four;
        }
        return root;
    }
};