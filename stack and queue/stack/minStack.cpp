/*
    MIN STACK
    https://leetcode.com/problems/min-stack
*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<int> st;
    int minVal;
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            minVal = val;
        } else if(val <= minVal) {
            st.push_back(minVal);
            minVal = val;
        }
        st.push_back(val);
    }
    
    void pop() {
        int top = st.back();
        st.pop_back();
        if(top == minVal && !st.empty()) {
            minVal = st.back();
            st.pop_back();
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minVal;
    }
};