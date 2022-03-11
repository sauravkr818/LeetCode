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
        if(k == 0) return head;
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int n = 0;
        while(temp->next != NULL){
            temp = temp->next;
            n += 1;
            //cout<<n<<endl;
        }
        ListNode* last = temp;
        temp = head;
        n++;
        cout<<n<<endl;
        if(n == 1 || k % n == 0) return head;
        if(k>=n) k = k%n;
        int nok = n-k-1;
        while(nok--){
            temp = temp->next;
        }
        cout<<temp->val<<endl;
        ListNode* temp2 = temp;
        
        temp = temp->next;
        ListNode* ans = temp;
        temp2->next = NULL;
        
        last->next = head;
        
        return ans;
        
    }
};