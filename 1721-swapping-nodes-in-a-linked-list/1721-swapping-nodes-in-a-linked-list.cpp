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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp2 = head;
        ListNode* one = head;
        ListNode* two = head;
        ListNode* temp = head;
        int count = 1;
        while(temp2 != NULL){
            if(count == k){
                one = temp2;
            }
            else if(count>k){
                two = two->next;
            }
            temp2 = temp2->next;
            count++;
        }
        swap(one->val,two->val);
        return temp;
    }
};