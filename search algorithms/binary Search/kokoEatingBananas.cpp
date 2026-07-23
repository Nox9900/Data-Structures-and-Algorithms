

/*
    KOKO EATING BANANAS
    https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right) {
            int mid = left + (right-left) / 2;
            long long totalHours = 0;
            for(int& pile : piles) {
                totalHours += (pile+mid-1) / mid;
            }
            if(totalHours <= h) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution {
public:
long long calculateTotalHours(vector<int>& piles, int speed ){
    long long totalH = 0;
    for(int bananas : piles){
       totalH += (bananas + (long long)speed - 1) / speed;
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = *max_element(piles.begin(), piles.end());
         int low =1, high = maxpile;
        int ans = maxpile;
         while(low<=high){
            int mid = (low+high)/2;
            long long totalH = calculateTotalHours(piles, mid);

            if(totalH<=h){
                ans = mid;
                high =mid - 1;
            }
            else{
                low = mid+1;
            }
         }
         return ans;

    }
};