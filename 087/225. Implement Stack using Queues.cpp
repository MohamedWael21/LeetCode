class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        queue<int>temp;
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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