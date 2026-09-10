class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        backtrack(0, turnedOn, 0);
        return ans;
    }
private:
    vector<string> ans;
    
    void backtrack(uint16_t bits, int leds, uint8_t pos){
        if(leds == 0){
            int hours = (bits & 0b1111000000) >> 6;
            int minutes = (bits & 0b0000111111);

            if(hours >= 12 || minutes >= 60)
                return;

            string time = to_string(hours) + ':'; 
            time += minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
            ans.push_back(time);
            return;
        }
        for(uint8_t i = pos; i < 10; ++i){
            bits = bits | (1 << i);
            backtrack(bits, leds-1, i+1);
            bits = bits ^ (1 << i); //backtrack
        }
    }
};