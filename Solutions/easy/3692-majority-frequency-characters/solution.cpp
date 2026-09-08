class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> frequency(26, 0);

        for (char c : s)
            ++frequency[c - 'a'];
        
        vector<string> groups(101);

        for (int i = 0; i < 26; ++i){
            int freq = frequency[i];
            if(freq != 0)
                groups[freq] += i + 'a';
        }
        
        int greatestGroup = INT32_MIN, index = 0;

        for (int i = 100; i >= 1; --i) {
            if((int)groups[i].size() > greatestGroup){
                greatestGroup = groups[i].size();
                index = i;
            }
        }
        return groups[index];
    }
};