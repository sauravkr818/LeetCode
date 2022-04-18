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
    int i = 0;
    bool visit = false;
    void f(TreeNode* root, int &k){
        if(k == 0) return;
        if(root == NULL) {
            visit = true;
            return;
        }
        if(visit && root->left)f(root->left,k);
        else f(root->left,k);
        
        if(k == 0) return;
        
        if(root && k != 0){
            count = root->val;
            cout<<count<<" ";
            k--;
            cout<<k<<" ";
            cout<<endl;
        }
        
        
        if(visit && root->right) f(root->right,k);
        else f(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return count;
    }
};