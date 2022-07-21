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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode*temp = head;
        ListNode*one = head->next;
        while(one!=NULL){
            ListNode* two = one->next;
            one->next = head;
            if(one!=NULL) head = one;
            one = two;
            
        }
        temp->next = NULL;
        return head;
    }
};