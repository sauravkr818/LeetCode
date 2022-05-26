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
        unordered_set<ListNode*>h1;
        unordered_set<ListNode*>h2;
        while(headA and headB){
            if(h2.count(headA) == 1){
                return headA;
            }
            else{
                h1.insert(headA);
            }
            if(h1.count(headB) == 1){
                return headB;
            }
            else{
                h2.insert(headB);
            }
            headA = headA->next;
            headB = headB->next;
        }
        if(headA == NULL && headB == NULL)
        return NULL;
        else if(headA == NULL){
            while(headB!=NULL){
                if(h1.count(headB) == 1){
                return headB;
                }
                else{
                    h2.insert(headB);
                }
                    headB = headB->next;
            }
        }
        else if(headB == NULL){
            while(headA!=NULL){
                if(h2.count(headA) == 1){
                return headA;
                }
                else{
                    h1.insert(headA);
                }
                    headA = headA->next;
            }
        }
        return NULL;
    }
};