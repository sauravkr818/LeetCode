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
    int count = 0;
    //bool visit = false;
    void f(TreeNode* root, int &k){
        
        if(k == 0) return;
        
        if(root == NULL) {
            return;
        }
        f(root->left,k);
        
        if(root && k != 0){
            count = root->val;
            k--;
        }
        f(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return count;
    }
};