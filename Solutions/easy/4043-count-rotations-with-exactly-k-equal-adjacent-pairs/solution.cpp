class Solution {
public:
    int countRotations(string s, int k) {
        deque<char> dq(s.begin(), s.end()); 
        
        auto validate = [&](){
            int count = 0;

            for(int i = 0; i < dq.size()-1; ++i){
                if(dq[i] == dq[i+1])
                    ++count;
            }

            return count == k;
        };
        
        int ans = 0;
        for(int r = 0; r < s.size(); ++r){
            if(validate()){
                ++ans;
            }

            dq.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};