class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; //monotonic increasing
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();

                int h = heights[idx];
                int left = st.empty() ? -1 : st.top();
                int right = i - 1;
                
                ans = max(ans, (right - left) * h);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
                int idx = st.top();
                st.pop();

                int h = heights[idx];
                int left = st.empty() ? -1 : st.top();
                int right = heights.size() - 1;
                
                ans = max(ans, (right - left) * h);
        }

        return ans;
    }
};