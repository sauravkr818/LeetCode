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
    bool solve(TreeNode* root, TreeNode* p, vector<int>& path, bool &got){
        if(!root) return false;
        path.push_back(root->val);
        if(root->val == p->val){
            got = true;
            return true;
        }
        bool ls,rs;
        //if(!got)
        ls = solve(root->left,p,path,got);
        //if(!got)
        rs = solve(root->right,p,path,got);
        if(!got && !ls && !rs){
            path.pop_back();
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1st method
        // 3 traversal
        // Building path arrays
        // Path array-1
        vector<int>path1;
        bool got = false;
        solve(root,p,path1,got);
        
        // Path array-2
        vector<int>path2;
        bool got2 = false;
        solve(root,q,path2,got2);
        int i;
        for( i=0;i<path1.size() && i<path2.size();i++ ){
            if(path1[i]!=path2[i]){
                break;
            }
        }
        TreeNode* ans = new TreeNode(path1[--i]);
        return ans;
    }
};