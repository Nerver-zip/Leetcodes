typedef struct StackNode
{
    int val;
    StackNode* next;
    StackNode* nextMin;
    StackNode(int val) : val(val), next(nullptr), nextMin(nullptr) {}
}StackNode;

typedef struct MyStack
{
    StackNode* first;
    MyStack() : first(nullptr){}
}MyStack;

class MinStack {
private:
    MyStack* myMinStack;
    StackNode* currentMin;
public:
    MinStack() {
        myMinStack = new MyStack();
    }

    ~MinStack(){
        while (!isEmpty())
        {
            pop();
        }
    }
    
    void push(int val) {
        StackNode* newNode = new StackNode(val);

        if(!isEmpty()){
            newNode->next = myMinStack->first;
            myMinStack->first = newNode;
            if(newNode->val < currentMin->val)
            {
                newNode->nextMin = currentMin;
                currentMin = newNode;
            }
            return;
        }
        myMinStack->first = newNode;
        currentMin = newNode;
    }
    
    void pop() {
        if (!isEmpty())
        {
            StackNode* temp = myMinStack->first;
            if (temp == currentMin)
                currentMin = currentMin->nextMin;
            
            myMinStack->first = myMinStack->first->next;
            delete(temp);
        }
    }
    
    int top() {
        if (!isEmpty())
        {
            return myMinStack->first->val;
        }
        return -1;
    }
    
    int getMin() {
        return currentMin->val;
    }

    bool isEmpty(){
        return myMinStack->first == nullptr;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */