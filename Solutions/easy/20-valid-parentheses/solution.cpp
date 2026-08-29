class Solution {
public:
    bool isValid(string str) {
        std::stack<int> stack;

        for (char s : str)
        {
            if(s == '(' || s == '[' || s == '{')
                stack.push(s);
            else
            {
                if (stack.empty()) return false;
                if(stack.top() == '(' && (s == ']' || s == '}')) return false;
                if(stack.top() == '[' && (s == ')' || s == '}')) return false;                                           
                if(stack.top() == '{' && (s == ')' || s == ']')) return false;
                
                stack.pop();
            }
        }
        return stack.empty();
    }
};