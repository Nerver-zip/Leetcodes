#define INFINITE 100000000
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int time = 0;

        vector<int> letterFrequency(26,0);
        vector<int> letterTime(26, 0); //time when process was last executed, compare it to global time when needed

        for (const auto& c : tasks)
        {
            letterFrequency[c - 'A']++;
            letterTime[c - 'A'] = INFINITE; //first time it appears the wait has been infinte
        } 

        priority_queue<pair<int,char>, vector<pair<int,char>>> maxHeap; //freq, char
        
        for (int i = 0; i < letterFrequency.size(); i++)
            if (letterFrequency[i] > 0)
                maxHeap.push({letterFrequency[i], i + 'A'});

        while (!maxHeap.empty())
        {
            //pick most frequent letter
            auto [freq, c] = maxHeap.top();
            int currTime = letterTime[c - 'A'];

            //can place immediately
            if (time - currTime >= n || currTime == INFINITE)
            {
                time++;
                letterFrequency[c - 'A']--;
                letterTime[c - 'A'] = time;
                maxHeap.pop();
                if (letterFrequency[c - 'A'] > 0)
                    maxHeap.push({letterFrequency[c - 'A'], c});
            }
            //get most frequent letter the can be placed immediately, otherwise, wait 
            else
            {
                stack<pair<int, char>> undo;
                char c2;
                while (!maxHeap.empty() && currTime != INFINITE && time - currTime < n )
                {
                    c2 = maxHeap.top().second;
                    currTime = letterTime[c2 - 'A'];
                    undo.push(maxHeap.top());
                    maxHeap.pop();
                }
                if (maxHeap.empty()) //wait
                {
                    //check if last element was actually used instead of waiting 
                    if (!undo.empty() && (currTime == INFINITE || time - currTime >= n))
                    {
                        time++;
                        letterTime[c2 - 'A'] = time;
                        letterFrequency[c2 - 'A']--;
                        if (letterFrequency[c2 - 'A']-- > 0)
                            maxHeap.push({letterFrequency[c2 - 'A'], c2});
                        undo.pop();
                    }
                    else //otherwise, just wait
                    {
                        time++;
                    }
                    while (!undo.empty())
                    {
                        maxHeap.push(undo.top());
                        undo.pop();
                    }
                }
                else //c2 can be placed
                {
                    time++;
                    letterFrequency[c2 - 'A']--;
                    letterTime[c2 - 'A'] = time;
                    undo.pop();
                    if (letterFrequency[c2 - 'A'] > 0)
                        maxHeap.push({letterFrequency[c2 - 'A'], c2});

                    while (!undo.empty())
                    {
                        maxHeap.push(undo.top());
                        undo.pop();
                    }
                }
            }
        }
        return time;
    }
};