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
        // use the concept of slow and fast pointer;
        // We use the fact that if there is a cycle exist then slow and fast pointer will definitely meet at somewhere;
        // if there is no cycle then they will not meet and fast will reach to null
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