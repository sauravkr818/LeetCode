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
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* temp = NULL;
        while(head){
            ListNode* temp2 = head;
            head = head->next;
            temp2->next = temp;
            temp = temp2;
        }
        return temp;
    }
};