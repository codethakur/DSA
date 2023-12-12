class MinStack {
public:
    stack<int> s;   // Original stack to store values
    stack<int> ss;  // Stack to store minimum values

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty() || ss.top() > val){
            ss.push(val);
        } else {
            ss.push(ss.top());
        }
    }
    
    void pop() {
        if(s.empty()){
            cout << "-1" << endl;
            return;
        }
        s.pop();
        ss.pop();
    }
    
    int top() {
        if(s.empty()) {
            return -1;
        }
        return s.top();
    }
    
    int getMin() {
        if(ss.empty()) {
            return -1;
        }
        return ss.top();
    }
};
