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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(n == 0) return head;
        ListNode* en = head;
        n = n-1;
        while(n--){
            en = en->next;
        }
        if(en == NULL) return head->next;
        if(en->next == NULL) return head->next;
        ListNode* st = head;
        ListNode* st_before = new ListNode();
        st_before->next = head;
        while(en->next != NULL){
            st_before = st_before->next;
            st = st->next;
            en = en->next;
        }
        st_before->next = st->next;
        return head;
    }
};