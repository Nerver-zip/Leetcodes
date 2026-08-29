typedef struct MyListNode
{
    int val;
    MyListNode* next;
    MyListNode() : val(0), next(nullptr){}
    MyListNode(int x) : val(x), next(nullptr){}
}MyListNode;


class MyLinkedList {
private:
    MyListNode* head;
    MyListNode* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~MyLinkedList() {
        while (head != nullptr)
        {
            MyListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    
    int get(int index) {
        int count = 0;
        MyListNode* temp = head;
        if(index >= size) return -1;
        while (count < index)
        {
            temp = temp->next;
            count++;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        if (head == nullptr)
        {
            head = new MyListNode(val);
            tail = head;
            size++;
            return;
        }
        MyListNode* temp = new MyListNode(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        if (tail == nullptr)
        {
            tail = new MyListNode(val);
            head = tail;
            size++;
            return;
        }
        tail->next = new MyListNode(val);
        tail = tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) 
            return;
        if (index == size){
            addAtTail(val);
            return;
        }
        if(index == 0){
           addAtHead(val);
           return; 
        }
        int count = 1;
        MyListNode* prev = head;
        MyListNode* temp = prev->next;
        while (count < index && temp != nullptr)
        {
            temp = temp->next;
            prev = prev->next;
            count++;
        }
        MyListNode* newNode = new MyListNode(val);
        prev->next = newNode;
        newNode->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || head == nullptr) return;
        if (index == 0){
            MyListNode* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            size--;
            return;
        }
        if (index == size - 1)
        {   
            MyListNode* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            delete temp->next;
            tail->next = nullptr;
            size--;
            return;
        }

        int count = 1;
        MyListNode* prev = head;
        MyListNode* temp = prev->next;

        while (count < index && temp != nullptr)
        {
            temp = temp->next;
            prev = prev->next;
            count++;
        }
        prev->next = temp->next;
        delete temp;
        size--;
    }
};