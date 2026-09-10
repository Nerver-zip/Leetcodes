class Solution {
    public:
        string clearDigits(string s) {
            
            std::deque<int> myQueue;
    
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 48 && s[i] <= 57)
                    myQueue.pop_back();
                else
                    myQueue.push_back(s[i]);
            }

            string ans;

            while (!myQueue.empty())
            {
                ans += myQueue.front();
                myQueue.pop_front();
            }
            
            return ans;
        }
    };