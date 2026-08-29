class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        auto getTopTwo = [&](){
            int n2 = s.top();
            s.pop();
            int n1 = s.top();
            s.pop();

            return pair<int,int>(n1, n2);
        };

        for (auto token : tokens) {
            if(token == "+"){
                auto [n1, n2] = getTopTwo();
                s.push(n1 + n2);
            }
            else if(token == "-"){
                auto [n1, n2] = getTopTwo();
                s.push(n1 - n2);
            }
            else if(token == "*"){
                auto [n1, n2] = getTopTwo();
                s.push(n1 * n2);
            }
            else if(token == "/"){
                auto [n1, n2] = getTopTwo();
                s.push(n1 / n2);
            }
            else {
                int n = atoi(token.c_str());
                s.push(n);
            }
        } 
        
        return s.top();
    }
};