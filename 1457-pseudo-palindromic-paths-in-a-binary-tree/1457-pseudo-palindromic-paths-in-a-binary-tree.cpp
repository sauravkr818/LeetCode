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
    int ans = 0;
    map<int,int>mp;
    
    void f(TreeNode* root){
        if(root == NULL) return;
        
        mp[root->val]++;
        
        if(root->left == NULL && root->right == NULL){
            int c = 0;
            for(auto it: mp){
                if(it.second %2 != 0){
                    c++;
                }
            }
            if(c<=1){
                ans++;
            }
            mp[root->val]--;
            return;
        }
        
        pseudoPalindromicPaths (root->left);
        pseudoPalindromicPaths (root->right);
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        f(root);
        return ans;
    }
};