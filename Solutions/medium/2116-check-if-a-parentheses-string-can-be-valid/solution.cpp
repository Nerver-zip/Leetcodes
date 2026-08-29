class Solution {
public:
    bool canBeValid(string s, string locked) {
        std::stack<int> lockedStack;
        std::stack<int> unlockedStack;

        if (s.size() % 2 != 0)
            return false;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (locked[i] == '0')
                unlockedStack.push(i);
            else if(s[i] == '(')
                lockedStack.push(i);
            else
            {
                if (!lockedStack.empty())
                    lockedStack.pop();
                else if(!unlockedStack.empty())
                    unlockedStack.pop();
                else // (lockedStack.empty() && unlockedStack.empty())
                {
                    return false;
                }
            }
        }
            while (!unlockedStack.empty() && !lockedStack.empty())
            {
                if (lockedStack.top() < unlockedStack.top())
                {
                    lockedStack.pop();
                    unlockedStack.pop();
                }
                else
                    break;
            }

        if (!lockedStack.empty())
            return false;

        return true;
    }
};
