class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<>> minHeap;
        
        auto isVowel = [](char c){
            return c == 'a' || c == 'e' || c == 'i' ||c == 'o' ||
            c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        for (char c : s)
            if(isVowel(c))
                minHeap.push(c);
        
        string ans;
        
        for (char c : s) {
            if(!isVowel(c))
                ans += c;
            else {
                ans += minHeap.top();
                minHeap.pop();
            }
        }
        
        return ans;
    }
};