class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        const int N = s.size();
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);

        auto add = [&](string word) {
            for (int i = 1; i < N; i += 2) {
                int c = (word[i] - '0' + a) % 10;
                word[i] = c + '0';
            }
            return word;
        };

        auto rotate = [&](const string& word){
            return word.substr(N-b) + word.substr(0, N-b);
        };
        
        string ans = s;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr < ans)
                ans = curr;
            
            string op1 = add(curr);
            if(!visited.count(op1)){
                q.push(op1);
                visited.insert(op1);
            }

            string op2 = rotate(curr);
            if(!visited.count(op2)){
                q.push(op2);
                visited.insert(op2);
            }
        }

        return ans;
    }
};
