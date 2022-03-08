/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* place = NULL;
            for(int i = 0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                temp->next = place;
                place = temp;
                // catch part -> first we insert right node then left node
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                
            }
        }
        
        return root;
    }
};