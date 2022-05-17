/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void newFn(TreeNode* cloned, TreeNode* target, TreeNode* &ans){
        if(cloned == NULL) return;
        if(cloned->val == target->val){
            ans = cloned;
        }
        newFn(cloned->left, target, ans);
        newFn(cloned->right, target, ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       // if(cloned == NULL) return NULL;        
        TreeNode *ans;
        newFn(cloned,target,ans);        
        return ans;
    }
};