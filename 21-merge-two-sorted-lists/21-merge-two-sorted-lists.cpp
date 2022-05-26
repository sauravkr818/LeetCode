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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* t = new ListNode();
        ListNode* m = t;
        while(list1 && list2){
            if(list1->val>list2->val){
                m->next = list2;
                list2 = list2->next;
            }
            else{
                m->next = list1;
                list1 = list1->next;
            }
            m = m->next;
        }
        if(!list1){
            m->next = list2;
        }
        else if(!list2){
            m->next = list1;
        }
        return t->next;
    }
};