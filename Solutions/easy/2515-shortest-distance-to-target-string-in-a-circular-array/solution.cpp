class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const int n = words.size();
        vector<int> indices;

        for(int i = 0; i < n; ++i)
            if(words[i] == target)
                indices.push_back(i);

        int ans = numeric_limits<int>::max();

        for(int i : indices)
            ans = min({ans, abs(i - startIndex), n - abs(i - startIndex)});
    
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};