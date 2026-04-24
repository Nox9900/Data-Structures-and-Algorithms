#include<bits/stdc++.h>
using namespace std;

class Solution {
    int palindrome(int x) {
        if(x<=0) return 0;
        int s=0, o=x;
        while(o != 0) {
            s = s*10 + 0%10;
            o /= 10;
        }
        return s==x;
    }
};