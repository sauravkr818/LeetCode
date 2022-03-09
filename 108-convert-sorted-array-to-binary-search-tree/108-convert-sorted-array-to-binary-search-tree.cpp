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
    
    TreeNode* rS(vector<int>&arr, int start,int end){
        if(start >= end) {
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = rS(arr,start,mid);
        root->right = rS(arr,mid+1,end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        
        return rS(arr,0,n);;
    }
};