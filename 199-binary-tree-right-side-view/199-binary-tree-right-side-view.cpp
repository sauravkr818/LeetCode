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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        
        
        if(root == NULL) return ans;
        q.push(root);
        ans.push_back(root->val);
        while(q.empty() == false){
            int size = q.size();
            TreeNode *saveLastNode = NULL;
            while(size>0){
                TreeNode* temp = q.front();q.pop();
                if(temp->left){
                    q.push(temp->left);
                    saveLastNode = temp->left;
                }
                if(temp->right){
                    q.push(temp->right);
                    saveLastNode = temp->right;
                }
                size--;
            }
            if(saveLastNode)
            ans.push_back(saveLastNode->val);
        }
        return ans;
    }
};