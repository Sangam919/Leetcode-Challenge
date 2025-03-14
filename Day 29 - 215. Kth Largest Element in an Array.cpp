class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
                priority_queue<int> heap(nums.begin(), nums.end());
                        while (--k) heap.pop();
                                return heap.top();
        }
}; 

        
