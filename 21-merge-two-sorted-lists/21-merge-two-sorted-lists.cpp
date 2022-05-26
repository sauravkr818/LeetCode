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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* ans;
        ListNode* ans2;
        if(t1->val>t2->val){
            ans = new ListNode(t2->val);
            t2 = t2->next;
            ans2 = ans;
        }
        else{
            ans = new ListNode(t1->val);
            t1 = t1->next;
            ans2 = ans;
        }
        
        int t = 1;
        while(t1 != NULL && t2 != NULL){
            if(t1->val>t2->val){
                ans->next = new ListNode(t2->val);
                //ans = ans->next;
                t2 = t2->next;
            }
            else if(t1->val<t2->val){
                ans->next = new ListNode(t1->val);
                //ans = ans->next;
                t1 = t1->next;
            }
            else if(t1->val == t2->val){
                ans->next = new ListNode(t2->val);
                
                    ans = ans->next;
                    ans->next = new ListNode(t2->val);
                
                //ans = ans->next;
                t2 = t2->next;
                t1 = t1->next;
            }
            t++;
            ans = ans->next;
        }
        if(t1 == NULL){
            ans->next = t2;
        }
        else{
            ans->next = t1;
        }
        return ans2;
    }
};