#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int index = 0;
        int n = heights.size();

        while(index < n) {
            if(st.empty() || heights[index] >= heights[st.top()])
                st.push(index++);
            else {
                int top = st.top();
                st.pop();
                int area = heights[top] * (st.empty() ? index : index - st.top()-1);
                maxArea = max(maxArea, area);
            }
        }

        while(!st.empty()) {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? n : n - st.top()-1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};