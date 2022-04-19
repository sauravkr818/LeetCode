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
    
    void f2(TreeNode* root,int i, int j, vector<int>&arr,TreeNode* &first, TreeNode* &second){
        if(first != NULL && second != NULL) return;
        if(root == NULL) return;
        if(root-> val == arr[i]) first = root;
        if(root-> val == arr[j]) second = root;
        f2(root->left,i,j,arr,first,second);
        arr.push_back(root->val);
        f2(root->right,i,j,arr,first,second);
    }
    
    void f(TreeNode* root,vector<int>&arr){
        if(root == NULL) return;
        f(root->left,arr);
        //cout<<root->val<<endl;
        arr.push_back(root->val);
        f(root->right,arr);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* one = root;
        vector<int>arr;
        f(root,arr);
        int i;
        for(i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]){
                break;
            }
        }
        //cout<<arr[i-1]<<" ";
        int j = i;
        while(j<arr.size() && arr[i-1]>arr[j]){
            //cout<<" j : "<<j<<endl;
            j++;
            //cout<<" j : "<<j<<endl;
        }
        //cout<<arr[j];
        root = one;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        f2(root,i-1,j-1,arr,first,second);
        
        swap(first->val,second->val);
        
        //return one;
    }
};