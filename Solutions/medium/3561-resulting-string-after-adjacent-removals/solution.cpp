class Solution {
public:
    string resultingString(string s) {
        deque<char> queue;
        for (const auto& c : s)
        {
            if (queue.size() > 0 && (abs(queue.back() - c) == 1 || c == 'z' && queue.back() == 'a' || c == 'a' && queue.back() == 'z'))
            {
                queue.pop_back();
                continue;
            }
            queue.push_back(c);
        }
        string ans;
        while (!queue.empty())
        {
            ans += queue.front();
            queue.pop_front();
        }
        return ans;
    }
};