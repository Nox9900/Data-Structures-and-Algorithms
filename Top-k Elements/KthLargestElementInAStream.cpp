#include<vector>

/*
    KTH LARGEST ELEMENT IN A STREAM
    https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int& num:nums)
            add(num);
    }
    
    int add(int val) {
        if(minHeap.size() < k) {
            minHeap.push(val);
        }else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};


class KthLargest {
public:
    vector<int> heap;
    KthLargest(int k, vector<int>& nums) {
        heap.reserve(k);

        if(k>nums.size()){
            heap.push_back(-10000);
        }

        for(int i =0; i<k && i < nums.size(); i++){
            heap.push_back(nums[i]);
        }
        
        make_heap(heap.begin(),heap.end(), greater<>());

        for(int i =k; i<nums.size();i++){
            add(nums[i]);
        }
        
    }
    
    int add(int val) {
        if(heap.front()<val){
            pop_heap(heap.begin(),heap.end(),greater<>());
            heap.pop_back();
            heap.push_back(val);
            push_heap(heap.begin(),heap.end(),greater<>());
        }
        
        return heap.front();
    }
};

