class MyStack {
public:
    
    vector<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int a = q[q.size()-1];
        q.pop_back();
        return a;
    }
    
    int top() {
        int a = q[q.size()-1];
        //q.push_back(a);
        return a;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */