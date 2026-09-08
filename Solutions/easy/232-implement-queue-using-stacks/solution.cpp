class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        pushStack.push(x);  
    }
    
    int pop() {
        if(popStack.empty()){
            while(!pushStack.empty()){
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        
        if(!popStack.empty()){
            auto top = popStack.top();
            popStack.pop();
            return top;
        }

        return -1;
    }
    
    int peek() {
        if(popStack.empty()){
            while(!pushStack.empty()){
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        
        if(!popStack.empty()){
            auto top = popStack.top();
            return top;
        }

        return -1;
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
private:
    stack<int> pushStack;
    stack<int> popStack;
};