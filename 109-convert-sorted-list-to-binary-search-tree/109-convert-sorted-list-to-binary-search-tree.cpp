/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    ListNode* findMiddle(ListNode* head, ListNode* tail){
        ListNode* fast = head, *slow = head;
        while(fast != tail && fast->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    TreeNode* rS(ListNode* head, ListNode* tail){
        if(head == NULL || head == tail) {
            return NULL;
        }
        ListNode* mid = findMiddle(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = rS(head,mid);
        root->right = rS(mid->next, tail);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return rS(head, NULL);
    }
};