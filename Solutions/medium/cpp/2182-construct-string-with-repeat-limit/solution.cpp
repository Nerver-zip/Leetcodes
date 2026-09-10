class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::priority_queue<int> maxHeap;
        std::unordered_map<int,int> frequencyMap;

        string answer;
        int ogRepeatLimit = repeatLimit;

        for (int i = 0; i < s.size(); i++)
        {
            if (frequencyMap.find(s[i]) == frequencyMap.end())
            {
                maxHeap.push(s[i]);
            }
            frequencyMap[s[i]]++;
        }
        
        int last = 420;
        while (!maxHeap.empty())
        {   
            if(maxHeap.top() == last)
                repeatLimit--;
            else
                repeatLimit = ogRepeatLimit;
            
            if (repeatLimit == 0 && maxHeap.top() == last)
            {
                repeatLimit = ogRepeatLimit;
                int repeated = last;

                if (!maxHeap.empty() && maxHeap.top() == last)
                {
                    maxHeap.pop();
                }

                //empty heap at this point means we will break the rule if we continue
                if (maxHeap.empty())
                    return answer;
                
                answer += maxHeap.top();
                last = maxHeap.top();
                frequencyMap[last]--;
                    if(frequencyMap[last] == 0)
                        maxHeap.pop();
                maxHeap.push(repeated);
            }
            else
            {
                answer += maxHeap.top();
                last = maxHeap.top();
                frequencyMap[last]--;
                if(frequencyMap[last] == 0)
                    maxHeap.pop();
            }
            
        }
        return answer;
    }
};
