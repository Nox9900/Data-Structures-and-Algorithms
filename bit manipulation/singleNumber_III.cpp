#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int& c:nums) {
            freq[c]++;
        }
        vector<int>res;
        for(const auto& c:freq){
            if(c.second==1) res.push_back(c.first);
        }
        return res;
    }
};


//optinmal solution
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int xore=0;
       for(auto i:nums){
        xore=xore^i;
       }
       int ind=-1;
       for(int i=0;i<=31;i++){
        if(xore&(1<<i)) {
            ind=i;
            break;
        }
       }
       int xor1=0;
       int xor2=0;
       for(auto i:nums){
        if(i&(1<<ind)){
            xor1=xor1^i;
        }
        else{
            xor2=xor2^i;
        }
       }
       return {xor1,xor2};

    }
};