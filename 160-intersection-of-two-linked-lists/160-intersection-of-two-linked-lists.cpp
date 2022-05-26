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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* hA = headA;
        ListNode* hB = headB;
        while(headA){
            len1++;
            headA = headA->next;
        }
        while(headB){
            len2++;
            headB = headB->next;
        }
        cout<<len1<<" "<<len2;
        int diff = 0;
        if(len1>len2){
            diff = len1-len2;
            while(diff--){
                hA = hA->next;
            }
        }
        else{
            diff = len2-len1;
            while(diff--){
                hB = hB->next;
            }
        }
        while(hA && hB){
            if(hA == hB) return hA;
            hA = hA->next;
            hB = hB->next;
            
        }
        return NULL;
    }
};