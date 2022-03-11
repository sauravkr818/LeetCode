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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int n = 0;
        ListNode* temp = list1;
        ListNode* temp2 = list1;
        while(n != a-1){
            temp = temp->next;
            n += 1;
        }
        temp2 = temp;
        while(n != b && temp2 != NULL){
            temp2 = temp2->next;
            n += 1;
        }
        ListNode* temp3 = list2;
        while(temp3->next != NULL){
            temp3 = temp3->next;
        }
        // ListNode* aivehi = temp;
        // aivehi->next = NULL;
        //temp = temp->next;
        temp->next = list2;
        temp3->next = temp2->next;
        
        return list1;
    }
};