class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') 
                    heights[j]++;
                else 
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
private:
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