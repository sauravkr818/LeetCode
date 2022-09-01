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
    
    void f(TreeNode* root, stack<int>&st){
        if(root == NULL){
            return;
        }
        if(st.empty() == true){
            st.push(root->val);
            count++;
        }
        else if(st.empty() == false && root->val>=st.top()){
            st.push(root->val);
            count++;
        }
        else if(st.empty() == false && root->val<st.top()){
            st.push(st.top());
        }
        f(root->left,st);
        
        f(root->right,st);
        
        int t = st.top();
        st.pop();
        if(st.empty() == true){
            st.push(t);
        }
        
    }
    
    int goodNodes(TreeNode* root) {
        stack<int>st;
        f(root,st);
        return count;
    }
};