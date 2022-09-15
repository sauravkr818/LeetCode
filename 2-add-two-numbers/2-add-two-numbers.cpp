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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* ans = temp;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val;
            int rem = (sum+carry) % 10;
            carry = (sum+carry) / 10;
            ListNode *t = new ListNode(rem);
            temp->next = t;
            
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        
        while(l1){
            int rem = (l1->val+carry) % 10;
            carry = (l1->val+carry) / 10;
            ListNode *t = new ListNode(rem);
            temp->next = t;
            l1 = l1->next;
            temp = temp->next;
            
        }
        while(l2){
            int rem = (l2->val+carry) % 10;
            carry = (l2->val+carry) / 10;
            ListNode *t = new ListNode(rem);
            temp->next = t;
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry != 0){
            temp->next = new ListNode(carry);
        }
        return ans->next;
    }
};