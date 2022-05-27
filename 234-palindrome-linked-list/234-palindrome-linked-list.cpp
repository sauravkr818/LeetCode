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
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return true;
        
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        ListNode* temp = NULL;
        ListNode* save;
        while(slow){
            ListNode* save2 = slow;
            if(slow->next == NULL) save = slow;
            slow = slow->next;
            save2->next = temp;
            temp = save2;
            
        }
        while(count--){
            if(head->val != save->val) return false;
            
            head = head->next;
            save = save->next;
        }
        return true;
    }
};