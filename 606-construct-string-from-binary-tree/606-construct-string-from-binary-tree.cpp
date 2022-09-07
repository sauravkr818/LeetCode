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
    string s = "";
    void f(TreeNode* root, TreeNode* t){
        if(root == NULL){
            if(t != NULL && t->right != NULL){
                s += "()";
            }
            return;
        }
        s += '(';
        s += to_string(root->val);
        f(root->left,root);
        f(root->right,root);
        s += ')';
    }
    string tree2str(TreeNode* root) {
        s += to_string(root->val);
        f(root->left,root->left);
        if(root->left == NULL && root->right != NULL){
            s += "()";
        }
        f(root->right,root->right);
        return s;
    }
};