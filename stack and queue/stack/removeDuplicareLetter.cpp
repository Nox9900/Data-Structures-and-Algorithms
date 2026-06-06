/*
    REMOVE DUPLICATE LETTER
    https://leetcode.com/problems/remove-duplicate-letters/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> cnt(256, 0);
            vector<bool> instack(256, false);

            for(char& c:s) cnt[c]++;
            stack<char> st;
            for(char& c:s) {
                cnt[c]--;
                if(instack[c]) continue;
                while(!st.empty() && st.top()>c && cnt[st.top()] > 0) st.pop();

                st.push(c);
                instack[c] = true;
            }

            string result = "";
            while(!st.empty()) {
                result += st.top();
                st.pop();
            }

            reverse(result.begin(), result.end());
            return result;
        }
};