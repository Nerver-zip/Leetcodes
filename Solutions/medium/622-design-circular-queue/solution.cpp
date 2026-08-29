class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        MAX_CAPACITY = k;
    }
    
    bool enQueue(int value) {
        if(linkedList.size() < MAX_CAPACITY){
            linkedList.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!linkedList.empty()){
            linkedList.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        return linkedList.empty() ? -1 : linkedList.front();
    }
    
    int Rear() {
        return linkedList.empty() ? -1 : linkedList.back();
    }
    
    bool isEmpty() {
        return linkedList.empty();
    }
    
    bool isFull() {
        return linkedList.size() == MAX_CAPACITY;
    }
private:
    list<int> linkedList;
    int MAX_CAPACITY;
};