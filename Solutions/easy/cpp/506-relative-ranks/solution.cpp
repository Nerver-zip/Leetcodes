class Heap
{
private:
    std::tuple<int,int>* array;
    int capacity;
    int size;

    void insert(int value, int index){
        this->array[this->size] = std::make_tuple(value,index);
        this->size++;
    }

    void heapify(std::tuple<int,int> array[], int index, int size){
        int left = index*2;
        int right = index*2 + 1;
        int greatestIndex = greatest(array,index,left,right,size);

        if (greatestIndex != index)
        {
            swap(array[greatestIndex],array[index]);
            heapify(array,greatestIndex,size);
        }
    }

    void heapifyUp(std::tuple<int,int> array[], int index){
        if (index > 1)
        {
            int parentIndex = index/2;
            if (std::get<0>(array[index]) > std::get<0>(array[parentIndex]))
            {
                swap(array[index],array[parentIndex]);
                heapifyUp(array,parentIndex);
            }
        }
        
    }

    int greatest(std::tuple<int,int> array[], int index, int left, int right, int size){
        int great = index;
        if (right <= size && std::get<0>(array[right]) > std::get<0>(array[great]))
        {
            great = right;
        }
        if (left <= size && std::get<0>(array[left]) > std::get<0>(array[great]))
        {
            great = left;
        }
        return great;
    }

    void swap(std::tuple<int,int> &a, std::tuple<int,int> &b){
        std::tuple<int,int> temp = a;
        a = b;
        b = temp;
    }

public:
    Heap(int capacity = 1000001) : capacity(capacity), size(1) {
        this->array = new std::tuple<int, int>[capacity];
    }

    ~Heap() {
        delete[] this->array;
    }

    int enqueue(int value,int index){
        if (this->capacity > this->size)
        {
            insert(value,index);
            heapifyUp(this->array,this->size-1);
            return 0; //success
        }
        return -1; //failed
    }

    std::tuple<int,int> dequeue(){
        if (this->size > 1)
        {
            int lastIndex = this->size-1;
            std::tuple<int,int> topo = this->array[1];
            this->array[1] = this->array[lastIndex];
            this->size = this->size-1;
            heapify(this->array,1,this->size-1);
            return topo;
        }
        return std::make_tuple(-1,-1);
    }

    std::tuple<int,int> peek(){
        return this->size > 1 ? this->array[1] : std::make_tuple(-1,-1);
    }

    bool isEmpty(){
        return this->size == 1 ? true : false;
    }

};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if(score.size() == 0) return {};
        Heap heap;
        for (int i = 0; i < score.size(); i++)
        {
            heap.enqueue(score[i],i);
        }
        vector<string> answer(score.size());

        //3 special cases
        int count = 0;
        if (!heap.isEmpty()) answer[std::get<1>(heap.dequeue())] = "Gold Medal";
        if (!heap.isEmpty()) answer[std::get<1>(heap.dequeue())] = "Silver Medal";
        if (!heap.isEmpty()) answer[std::get<1>(heap.dequeue())] = "Bronze Medal";
        
        //Fill the rest with respective rank number
        std::tuple<int,int> temp;
        int rank = 4;
        while (!heap.isEmpty())
        {
            temp = heap.dequeue();
            answer[std::get<1>(temp)] = std::to_string(rank);
            rank++;
        }
        return answer;
    }
};