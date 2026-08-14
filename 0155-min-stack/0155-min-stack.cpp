class MinStack {
    stack<long long int> s;
    long long int mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            mini = value;
        }else{
            if(value<mini){
                s.push((long long)2*value - mini);
                mini = value;
            }else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top() < mini){
            mini = 2*mini - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < mini){
            return mini;
        }
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */