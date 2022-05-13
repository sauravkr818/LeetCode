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
        if(root == NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(q.empty() == false){
            Node* temp1 = NULL;
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp2 = q.front();
                q.pop();
                temp2->next = temp1;
                temp1 = temp2;
                if(temp2->right) q.push(temp2->right);
                if(temp2->left) q.push(temp2->left);
            }
        }
        return root;
    }
};