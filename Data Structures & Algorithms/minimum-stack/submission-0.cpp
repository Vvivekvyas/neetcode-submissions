class MinStack {
private:
stack<int>st;
stack<int>mins;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val = min(val,mins.empty() ? val : mins.top());
        mins.push(val);
    }
    
    void pop() {
        st.pop();
        mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
