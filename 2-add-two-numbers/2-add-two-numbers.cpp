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
        ListNode* ans = new ListNode();
        ListNode* ans2 = ans;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int add = l1->val + l2->val;
            int rem = add%10;
            if(add>=10){
                ListNode* temp = new ListNode(carry+rem);
                ans->next = temp;
                ans = ans->next;
                carry = add/10;
            }
            else{
                if(carry+add>=10){
                    int rem1 = (carry+add)%10;
                    ListNode* temp = new ListNode(rem1);
                    carry = (carry+add)/10;
                    ans->next = temp;
                    ans = ans->next;
                }
                else{
                    ListNode* temp = new ListNode(carry+add);
                    ans->next = temp;
                    ans = ans->next;
                    carry = 0;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 != NULL){
            ans->next = l1;
            ListNode* t = new ListNode();
            if(carry != 0)
            {
                while(l1->next != NULL){
                    if((carry+(l1->val))>=10){
                        int rem = (carry+l1->val)%10;
                        carry = (carry+l1->val)/10;
                        l1->val = rem;
                        l1 = l1->next;
                    }
                    else{
                        l1->val += carry;
                        carry = 0;
                        l1 = l1->next;
                        //break;
                    }
                    // if(l1->next == NULL) t = l1;
                }
                t = l1;
                if((carry+(l1->val))>=10){
                        int rem = (carry+l1->val)%10;
                        carry = (carry+l1->val)/10;
                        l1->val = rem;
                        l1 = l1->next;
                    }
                    else{
                        l1->val += carry;
                        carry = 0;
                        //l1 = l1->next;
                        //break;
                    }
            }
            if(carry != 0){
            ans = t;
            ListNode *temp = new ListNode(carry);
            ans->next = temp;
        }
        }
        else if(l1 == NULL && carry != 0){
            ListNode* t = new ListNode(carry);
            ans->next = t;
        }
        
        if( l2!=NULL ){
            ans->next = l2;
            ListNode* t = new ListNode();
            if(carry != 0)
            {
                while(l2->next != NULL){
                    if((carry+(l2->val))>=10){
                        int rem = (carry+l2->val)%10;
                        carry = (carry+l2->val)/10;
                        l2->val = rem;
                        l2 = l2->next;
                    }
                    else{
                        l2->val += carry;
                        carry = 0;
                        l2 = l2->next;
                        //break;
                    }
                    //if(l2->next == NULL) t = l2;
                }
                t = l2;
                if((carry+(l2->val))>=10){
                        int rem = (carry+l2->val)%10;
                        carry = (carry+l2->val)/10;
                        l2->val = rem;
                        l2 = l2->next;
                    }
                    else{
                        l2->val += carry;
                        carry = 0;
                        //l2 = l2->next;
                        //break;
                    }
            }
            if(carry != 0){
            ans = t;
            ListNode *temp = new ListNode(carry);
            ans->next = temp;
        }
        }
        else if(l2 == NULL && carry != 0){
            ListNode* t = new ListNode(carry);
            ans->next = t;
        }
        
        return ans2->next;
    }
};