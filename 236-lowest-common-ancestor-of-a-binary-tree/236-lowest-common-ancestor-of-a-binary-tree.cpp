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
    bool getPath(TreeNode*root, TreeNode*p, vector<TreeNode*>&path){
        if(root == NULL) return false;
        path.push_back(root);
        
        if(root->val == p->val){
            return true;
        }
        if(getPath(root->left,p,path) || getPath(root->right,p,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        getPath(root,p,path1);
        //for(auto t: path1) cout<<t->val<<endl;
        vector<TreeNode*>path2;
        getPath(root,q,path2);
        //for(auto t: path2) cout<<t->val<<endl;
        int i = 0;
        for(i=0;i<path1.size() && i<path2.size(); i++){
            if((path1[i])->val != (path2[i])->val){
                break;
            }
        }
        return path1[i-1];
    }
};