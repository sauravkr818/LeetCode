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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;
        ListNode*cur = head;
        // phase 1 - getting the left pointer
        for(int i=0;i<left-1;i++){
            cur = cur->next;
            prev = prev->next;
        }
        // phase 2 - reversing from left to right
        ListNode* p = NULL;
        for(int i=0;i<right-left+1;i++){
            ListNode* save = cur->next;
            cur->next = p;
            p = cur;
            cur = save;
        }
        
        // phase 3 - reassigning the pointers prev,curr,p
        // prev is pointing just before left
        // curr is pointing just after right
        // p is pointing at right
        prev->next->next = cur;
        prev->next = p;
        return dummy->next;
    }
};