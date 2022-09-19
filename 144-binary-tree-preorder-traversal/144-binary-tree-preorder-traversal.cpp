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
    
    // first see the inorder traversal then come here if you are doing in Morris traversal way.
    // youtube link - striver - https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39
    
    
    //Morris Traversal - preorder
    // Here we consider the concept of binary threading where the rightmost node of the left subtree points back to the root.
    // This solution modifies the tree in between but later remodifies to make it original.
    // In other words, we make the threading first and then remove it later.
    
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        while(curr != NULL){
            // case 1:
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // case 2:
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                prev->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
                }
                else{ // if you came to see that you have already threaded this root then remove the thread/link and move to right.
                    prev->right = NULL;                    
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
