class Solution {
public:
    int countCollisions(string directions) {
        stack<int> st;
        
        int ans = 0;
        for (char c : directions) {
            
            if (!st.empty() && st.top() == 'R' && c != 'R') {
                //Extra points if it started with L 
                //After that it doesnt matter whats next (if its L or S)
                //Since no frontal collision between R and L will occur
                if(c == 'L') ++ans;
                while(!st.empty() && st.top() == 'R'){
                    st.pop();
                    ++ans;
                }
                //A collision create a stationary car
                st.push('S');
                continue;
            }
            else if(!st.empty() && st.top() == 'S' && c == 'L'){
                ++ans;
            }

            if(c == 'R' || c == 'S')
                st.push(c);
        }
        
        return ans;
    }
};