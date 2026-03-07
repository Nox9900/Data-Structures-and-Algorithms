#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt=0;
        vector<int> res(n);
        res[0] = nums[0];
        for(int i=1; i<n; i++) {
          res[i] = res[i-1] + nums[i];
          if(res[i] == k) cnt++;
        }
        return cnt;
    }
};

// optimal solution
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                res+=mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};