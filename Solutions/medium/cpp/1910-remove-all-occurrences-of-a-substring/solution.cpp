class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        std::stack<char> chars;

        for (int i = 0; i < s.size(); i++)
        {
            ans += s[i];

            if (ans.size() >= part.size() && ans.back() == part[part.size()-1])
            {
                std::stack<char> undoStack;
                for (int j = part.size()-1; j >= 0; j--)
                {
                    if (part[j] == ans.back())
                    {
                        undoStack.push(part[j]);
                        ans.pop_back();
                    }
                    else
                    {
                        while (!undoStack.empty())
                        {
                            ans += undoStack.top();
                            undoStack.pop();
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }    
};