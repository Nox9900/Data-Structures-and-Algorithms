#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> result(n+1, 0);
            for(int i=0; i<=n; i++) {
                int cnt=0, n=i;
                while(n) {
                    cnt += n&1;
                    n >>= 1;
                }
                result[i] = cnt;
            }

            return result;
        }
};

// optimal solution with O(log n)
class Solution2 {
    public:
        int countOnes(int k) {
        int count = 0;
        while (k) {
            ++count;
            k &= (k - 1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> count(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            count[i] = countOnes(i);
        return count;
    }
};