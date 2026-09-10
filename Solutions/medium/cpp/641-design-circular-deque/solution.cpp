typedef struct MyListNode
{
    int val;
    struct MyListNode* next;
    MyListNode(int x) : val(x), next(nullptr) {}
}MyListNode;

class MyCircularDeque {
private:
    MyListNode *front = nullptr;
    MyListNode *rear = nullptr;
    int size;
    int count;
public:
    MyCircularDeque(int k) {
        this->size = k;
        this->count = 0;
    }

    ~MyCircularDeque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
    
    bool insertFront(int value) {
        if(count == size) return false;
        MyListNode *newNode = new MyListNode(value);
        newNode->next = front;
        front = newNode;
        count++;
        if(rear == nullptr) rear = newNode;
        rear->next = front;
        return true;
    }
    
    bool insertLast(int value) {
        if(count == size) return false;

        MyListNode *newNode = new MyListNode(value);
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
            front->next = rear;
            rear->next = front;
            count++;
            return true;
        }
        rear->next = newNode;
        rear = rear->next;
        rear->next = front;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(count == 0) return false;

        MyListNode *temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
        count--;
        if (count == 0)
        {
            front = nullptr;
            rear = nullptr;
        }
        return true;
    }
    
    bool deleteLast() {
        if(count == 0) return false;

        MyListNode *temp = front;
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        rear = temp;
        temp = temp->next;
        delete temp;
        count--;
        if (count == 0)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            rear->next = front;
        }
        return true;
    }
    
    int getFront() {
        return !isEmpty() ? front->val : -1;   
    }
    
    int getRear() {
        return !isEmpty() ? rear->val : -1;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */