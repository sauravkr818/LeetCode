/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if(head == NULL) return false;
        while(true){
            if(slow->next == NULL) return false;
            else slow = slow->next;
            if(fast->next == NULL || fast->next->next == NULL) return false;
            else fast = fast->next->next;
            
            if(slow == fast) return true;
        }
    }
};