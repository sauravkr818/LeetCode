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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int h = 0;
        while(fast != NULL && fast->next != NULL ){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                h = 1;
                break;
            }
        }
        if(h == 1){
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast -> next;
        }
        return slow;
        }
        return NULL;
    }
};