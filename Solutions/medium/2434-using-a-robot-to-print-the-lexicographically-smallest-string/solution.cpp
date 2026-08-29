class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        stack<char> t;
        string result;
        char smallest = 'a';

        for (char c : s) {
            t.push(c);
            freq[c - 'a']--;

            while (smallest <= 'z' && freq[smallest - 'a'] == 0) {
                smallest++;
            }

            while (!t.empty() && t.top() <= smallest) {
                result += t.top();
                t.pop();
            }
        }

        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
