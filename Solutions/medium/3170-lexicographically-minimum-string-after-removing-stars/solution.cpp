struct Compare
{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const{
        return a.first == b.first ? a.second < b.second : a.first > b.first;
        //priority for mininum char, max index to untie 
    }
};

class Solution {
public:
    string clearStars(string s) {
        const int size = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> minHeap;
        vector<int> removed;

        for(int i = 0; i < size; ++i){
            if(s[i] != '*')
                minHeap.push({s[i], i});
            else
            {
                removed.push_back(minHeap.top().second);
                minHeap.pop();
            }
        }

        if (minHeap.size() == size)
            return s;
        
        string ans;
        sort(removed.begin(), removed.end());
        int j = 0;
        for (int i = 0; i < size; ++i)
        {
            if(j < removed.size() && i == removed[j])
                ++j;
            else if(s[i] != '*')
                ans += s[i];
        }
        return ans;
    }
};