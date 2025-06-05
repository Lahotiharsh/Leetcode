class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0, n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int bar = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                area = max(area, heights[bar] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int bar = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            area = max(area, heights[bar] * (nse - pse - 1));
        }

        return area;
    }
};