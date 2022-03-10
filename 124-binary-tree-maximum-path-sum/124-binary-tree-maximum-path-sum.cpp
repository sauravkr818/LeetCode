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
    int solve(TreeNode* root, int &sum){
        if(!root) return 0;
        
        int ls = solve(root->left,sum);
        int rs = solve(root->right,sum);
        if(ls<0) ls = 0;
        if(rs<0) rs = 0;
        sum = max(sum, root->val+ls+rs);
        return root->val + max(ls,rs);
        
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root,sum);
        return sum;
    }
};