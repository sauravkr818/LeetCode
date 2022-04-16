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
    int gsum = 0;
    int prev = 0;
    int f(TreeNode* root, int &sum,int &a, int &b){
        // base cases
        if(root == NULL) return 0;
        
        a = f(root->right,sum,a,b);
        gsum = prev + root->val;
        prev = gsum;
        sum = root->val + a;
        root->val = gsum;
        b = f(root->left,sum,a,b);
        return sum;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* temp = root;
        int a = 0, b = 0;
        f(root,sum,a,b);
        return temp;
    }
};