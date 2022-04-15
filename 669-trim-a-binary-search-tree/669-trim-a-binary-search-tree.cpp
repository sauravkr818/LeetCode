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
    void f(TreeNode*root, TreeNode* ans, int low, int high,TreeNode* &temp){
        if(root == NULL) return;
        if(root->val >= low && root->val <= high){
            if(ans == NULL){
                ans = new TreeNode(root->val);
                temp = ans;
                cout<<temp->val<<endl;
            }
            else if(ans != NULL && root != NULL){
                if(ans->val>=root->val){
                    ans->left = new TreeNode(root->val);
                    ans = ans->left;
                    cout<<ans->val<<endl;
                }
                else{
                    ans->right = new TreeNode(root->val);
                    ans = ans->right;
                    cout<<ans->val<<endl;
                }
            }
        }
        if(root != NULL) f(root->left,ans,low,high,temp);
         if(root != NULL) f(root->right,ans,low,high,temp);
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* ans = NULL;
        TreeNode* temp = ans;
        f(root,ans,low,high,temp);
        return temp;
    }
};