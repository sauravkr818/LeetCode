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
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        Node* ans = new Node(0);
        Node* save = ans;
        //ans->next = mp[temp];
        
        while(temp){
            ans->next = mp[temp];
            ans = ans->next;
            ans->random = mp[temp->random];
            temp = temp->next;
        }
        return save->next;
    }
};