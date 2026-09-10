class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::queue<int> open;
        std::queue<int> close;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open.push(i);
            else if(s[i] == ')') 
                if (open.empty())
                    close.push(i);
                else
                    open.pop();
        }

        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            int skipOpen = !open.empty() ? open.front() : -1;
            int skipClose = !close.empty() ? close.front() : -1;
            
            if (i == skipOpen)
            {
                open.pop();
                continue;
            }
            if (i == skipClose)
            {
                close.pop();
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};