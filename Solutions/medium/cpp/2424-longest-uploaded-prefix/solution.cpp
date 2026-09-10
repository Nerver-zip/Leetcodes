class LUPrefix {
private:
    std::vector<bool> stream;
    int lastValid;
public:
    LUPrefix(int n) {
        stream.resize(n+2); //avoid overflow, 1 indexed array
        lastValid = 0;
    }
    
    void upload(int video) {
        stream[video] = true;
    }
    
    int longest() {
        while (stream[lastValid+1])
        {
            lastValid++;
        }
        return lastValid;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */