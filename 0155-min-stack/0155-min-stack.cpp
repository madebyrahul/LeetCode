class MinStack {
    stack<int> values;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int value) {
        values.push(value);
        if(minStack.empty()){
            minStack.push(value);
        } else {
            minStack.push(min(value, minStack.top()));
        }
    }

    void pop() {
        values.pop();
        minStack.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minStack.top();
    }
};