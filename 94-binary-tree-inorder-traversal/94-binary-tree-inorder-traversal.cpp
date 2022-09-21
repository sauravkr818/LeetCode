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
    // vector<int>arr;
    // void f(TreeNode* root){
    //     if(!root) return;
    //     f(root->left);
    //     arr.push_back(root->val);
    //     f(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     f(root);
    //     return arr;
    // }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                // threading the rightmost guy to the cur
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                // removing the thread
                else{
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};