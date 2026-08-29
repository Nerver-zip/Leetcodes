class Solution {
private:
    string removedChars(const string& s, const string& tgt){
        stack<char> stack;
        for(const auto& c : s){
            if(!stack.empty() && stack.top() == tgt[0] && c == tgt[1])
                stack.pop();
            else
                stack.push(c);
        }
        
        string reconstructed;
        while (!stack.empty()) {
            reconstructed += stack.top();
            stack.pop();
        }
        reverse(reconstructed.begin(), reconstructed.end());
        return reconstructed;    
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string target = x > y ? "ab" : "ba";
        string target2 = target == "ab" ? "ba" : "ab";

        int size = s.size();

        string remaining = removedChars(s, target);
        
        ans += (size - remaining.size())/2 * max(x,y);

        size = remaining.size();

        remaining = removedChars(remaining, target2);

        ans += (size - remaining.size())/2 * min(x,y);

        return ans;
    }
};