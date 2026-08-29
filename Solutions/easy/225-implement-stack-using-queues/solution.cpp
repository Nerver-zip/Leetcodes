class MyStack {
    private:
    std::queue<int> stackedQueue;

public:
    MyStack() {
        
    }
    
    void push(int x) {
 
    stackedQueue.push(x);
    int size = stackedQueue.size()-1;
    for (int i = 0; i < size; i++)
    {
        int temp = stackedQueue.front();
        stackedQueue.pop();    
        stackedQueue.push(temp);
    }
    }
    
    int pop() {
        if (!stackedQueue.empty())
        {
           int val = stackedQueue.front();
           stackedQueue.pop();
           return val;   
        }
        return 0;
    }
    
    int top() {
        return (!stackedQueue.empty()) ? stackedQueue.front() : 0;
    }
    
    bool empty() {
        return stackedQueue.empty();
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