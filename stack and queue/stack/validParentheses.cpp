/*
    VALID PARENTHESES
    https://leetcode.com/problems/valid-parentheses
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        unordered_map<char, char>check = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        for(char& c:s) {
            if(check.count(c))
                if(!res.empty() && res.top() == check[c]) res.pop();
                else return false;
            else res.push(c);
        }
        return res.empty();
    }
};