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
    
    void f(TreeNode* root, int maxi, int &count){
        if(root == NULL){
            return;
        }
        if(root->val>=maxi){
            count++;
            maxi = root->val;
        }
        f(root->left,maxi,count);
        f(root->right,maxi,count);
        
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        f(root,INT_MIN,count);
        return count;
    }
};