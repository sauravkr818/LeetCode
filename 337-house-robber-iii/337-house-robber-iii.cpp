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
    int f(TreeNode* root, int &ans, map<TreeNode*,int>&m){
        if(root == NULL) return 0;
        if(m[root]) return m[root];
        int take = root->val;
        if(root->left){
            take += f(root->left->left,ans,m);
            take += f(root->left->right,ans,m);
        }
        if(root->right){
            take += f(root->right->right,ans,m);
            take += f(root->right->left,ans,m);
        }
        int non_take = 0;
        
        if(root->left){
            non_take += f(root->left,ans,m);
        }
        if(root->right){
            non_take += f(root->right,ans,m);
        }
        return m[root] = max(take,non_take);
        
    }
    
    int rob(TreeNode* root) {
        int ans = 0;
        map<TreeNode*,int>m;
        return f(root,ans,m);
    }
};