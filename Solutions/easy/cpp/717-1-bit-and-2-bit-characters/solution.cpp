class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    
        bool oneBit = false;
        for (int i = 0; i < bits.size(); ++i) {
            if(bits[i]){
                oneBit = false;
                ++i;
            }
            else
                oneBit = true;
        }

        return oneBit;
    }
};