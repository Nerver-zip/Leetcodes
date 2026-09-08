class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>, vector<pair<int,char>>> maxHeap;
        vector<int> frequency(26,0);
        string ans;

        for (const auto& c : s)
            frequency[c - 'a']++;
        
        for (int i = 0; i < frequency.size(); i++)
            if (frequency[i] > 0)
                maxHeap.push({frequency[i],i + 'a'});
    
        while (!maxHeap.empty()) //Combine highest frequency letter with second highest and so on
        {
            auto [freq_1, letter_1] = maxHeap.top();
            maxHeap.pop();
            ans += letter_1;

            if(maxHeap.empty())
                return freq_1 > 1 ? "" : ans;
            
            auto [freq_2, letter_2] = maxHeap.top();
            maxHeap.pop();
            ans += letter_2;

            if (freq_1 > 1) //push back elements which freq > 1
                maxHeap.push({freq_1 - 1, letter_1});
            if (freq_2 > 1)
                maxHeap.push({freq_2 - 1, letter_2});
        }
        return ans;
    }
};