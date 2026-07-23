

/*
    Kth Largest Element in a Array
    https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int& num : nums) {
            minHeap.push(num);
            if((int)minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};


// optimal soluiton
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (true) {
            int pivot = nums[left + rand() % (right - left + 1)];

            int lt = left;
            int i = left;
            int gt = right;

            while (i <= gt) {
                if (nums[i] < pivot)
                    swap(nums[lt++], nums[i++]);
                else if (nums[i] > pivot)
                    swap(nums[i], nums[gt--]);
                else
                    i++;
            }

            if (target < lt)
                right = lt - 1;
            else if (target > gt)
                left = gt + 1;
            else
                return nums[target];
        }
    }
};