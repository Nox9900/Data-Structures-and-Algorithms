#include <iostream>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            if(s == "") return true;
            if(s.size() > t.size()) return false;
            int j=0, i=0;
            
            while(i < s.size() && j < t.size()) {
                if(s[i] == t[j]) i++;
                j++;
            }
            return i == s.size();
        } 
};