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
    int ans = 0;
    const int MOD = 1E9 + 7;
    void dfs(TreeNode* root, int targetSum){
        if(root == NULL) return;

        if(root->val == targetSum) ans++;
        dfs(root->left,(targetSum-root->val)%MOD);
        dfs(root->right,(targetSum-root->val)%MOD);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};