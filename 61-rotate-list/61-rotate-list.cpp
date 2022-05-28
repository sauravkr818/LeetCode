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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
            
        }
        temp = head;
        int actual = k%n;
        if(actual == 0) return head;
        int it = n-actual-1;
        while(it--){
            temp = temp->next;
        }
        ListNode* save = temp;
        save = save->next;
        ListNode* ans = save;
        ListNode* save2 = new ListNode(0);
        temp->next = NULL;
        while(save){
            save2->next = save;
            save2 = save2->next;
            save = save->next;
        }
        save2->next = head;
        return ans;
    }
};