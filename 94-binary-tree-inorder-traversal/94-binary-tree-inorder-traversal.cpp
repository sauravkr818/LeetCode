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
    //Morris Traversal - https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39
    
    // Here we consider the concept of binary threading where the rightmost node of the left subtree points back to the root.
    // This solution modifies the tree in between but later remodifies to make it original.
    // In other words, we make the threading first and then remove it later.
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        while(curr != NULL){
            // case 1: when the root->left == NULL. In this case we would print the root and then move to the right.
            // because inorder is (left - root - right) and if left is NULL just print root and move to the right.
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // case 2: if root->left exist then just find the rightmost node and then connect its right to the root node of that left subtree tree.
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
                }
                else{ // if you came to see that you have already threaded this root then remove the thread/link, and print the root and move to right.
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};