/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* new_head = new Node(head->val);
        Node* save = head;
        head = head->next;
        Node* reserve = new_head;
        // created a map to access the nodes pointed by the random fastly in O(1);
        unordered_map<Node*,Node*>g;
        g[save] = new_head;
        
        // In this loop we first build the normal linked list with all the randoms pointing to NULL initially.
        
        while(head != NULL){
            Node* temp = new Node(head->val);
            g[head] = temp;
            new_head->next = temp;
            new_head = new_head->next;
            head = head->next;
        }
        head = save;
        new_head = reserve;
        
        // In this loop we done the remaining work. We accessed the Nodes to be pointed by the randoms of the new nodes.
        
        while(head != NULL){
            if(head->random == NULL){
                new_head->random = NULL;
            }
            else{
                new_head->random = g[head->random];
            }
            head = head->next;
            new_head = new_head->next;
        }
        
        return reserve;
    }
};