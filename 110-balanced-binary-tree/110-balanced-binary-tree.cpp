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
    int solve(TreeNode* root, bool &ans){
        if(!root) return 0;
        int ls = solve(root->left,ans);
        int rs = solve(root->right,ans);
        if(abs(ls-rs)>=2){
            ans = false;
        }
        return 1+ max(ls,rs);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};