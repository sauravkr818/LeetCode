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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeTwoLists(left,right);
    }
    
    
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
    
    
    ListNode* getMid(ListNode* head){
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};