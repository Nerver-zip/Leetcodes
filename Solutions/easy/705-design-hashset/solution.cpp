class MyHashSet {
private:
    bool mySet[1000001];
public:
    MyHashSet() {
        std::fill(mySet,mySet+1000001,false);
    }
    
    void add(int key) {
        mySet[key] = true;
    }
    
    void remove(int key) {
        mySet[key] = false;
    }
    
    bool contains(int key) {
        return mySet[key];
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */