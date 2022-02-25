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
    int path(TreeNode* root, int &maximum){
        if(!root) return 0;
        int leftSum = path(root->left,maximum);
        int rightSum = path(root->right,maximum);
        if(leftSum <0) leftSum = 0;
        if(rightSum<0) rightSum = 0;
        maximum = max(maximum,root->val+leftSum+rightSum);
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        path(root,maximum);
        return maximum;
    }
};