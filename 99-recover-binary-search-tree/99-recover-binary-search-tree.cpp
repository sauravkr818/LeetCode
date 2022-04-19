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
    void f(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
        if(root == NULL) return;
        f(root->left,prev,first,second);
        if(prev != NULL && root->val<prev->val){
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        f(root->right,prev,first,second);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        f(root,prev,first,second);
        swap(first->val,second->val);
    }
};