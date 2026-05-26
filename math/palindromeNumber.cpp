/*
    PALIMDROME NUMBER
    https://leetcode.com/problems/palindrome-number
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int IsPalindrome(int x) {
        if(x<0) return 0;
        long long s=0, o=x;
        while(o != 0) {
            s = s*10 + o%10;
            o /= 10;
        }
        return s==x;
    }
};