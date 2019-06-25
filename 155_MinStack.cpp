155_MinStack.cpp

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (x < min)
        {
            minSt.push(x);
            min = x;
        }
        else
        {
            minSt.push(min);
        }
    }
    
    void pop() {
        if (!st.empty())
        {
            st.pop();
            minSt.pop();
            if (minSt.empty())
                min = INT_MAX;
            else
                min = minSt.top();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
    int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */