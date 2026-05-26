#include<bits/stdc++.h>
using namespace std;

class SOlution {
public:
    int findMaxLenght(vector<int>& nums) {
        unordered_map<int, int> map;
        map[0] = -1;
        int lenght =0, balance=0;

        for(int i=0; i<nums.size(); i++) {
            balance += nums[i] == 1 ? 1 : -1;
            if(map.find(balance) != map.end()) {
                lenght = max(lenght, i-map[balance]);
            } else {
                map[balance] = i;
            }
        }
        return lenght;
    }
};