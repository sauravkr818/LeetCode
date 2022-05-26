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
        int carry = 0;
        ListNode* ans = new ListNode();ListNode* t = ans;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            int rem = sum%10;
            if(sum<10){
                carry = 0;
            }
            ListNode* temp;
            if(sum<10)
            temp = new ListNode(sum);
            else{
                temp = new ListNode(rem);
                carry = 1;
            }
            ans->next = temp;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 == NULL && l2 == NULL){
            if(carry == 1){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }
            return t->next;
        }
        else if(l1 == NULL){
            while(l2 != NULL){
                int sum = l2->val + carry;
                if(sum>=10){
                    carry = 1;
                    int rem = sum%10;
                    ListNode* temp = new ListNode(rem);
                    ans->next = temp;
                }
                else{
                    carry = 0;
                    ListNode* temp = new ListNode(sum);
                    ans->next = temp;
                }
                ans = ans->next;
                l2 = l2->next;
            }
        }
        else{
            while(l1 != NULL){
                int sum = l1->val + carry;
                if(sum>=10){
                    carry = 1;
                    int rem = sum%10;
                    ListNode* temp = new ListNode(rem);
                    ans->next = temp;
                }
                else{
                    carry = 0;
                    ListNode* temp = new ListNode(sum);
                    ans->next = temp;
                }
                ans = ans->next;
                l1 = l1->next;
            }
        }
        
        if(carry == 1){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }
        return t->next;
    }
};