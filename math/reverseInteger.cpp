#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int s = 0;
        while(x!=0){
            int p=x%10;
            x /= 10;
            if (s > INT_MAX/10 || (s == INT_MAX/10 && p > 7)) return 0;
            if (s < INT_MIN/10 || (s == INT_MIN/10 && p < -8)) return 0;
            s = s*10 + p;
        }
        return s;
    }
};