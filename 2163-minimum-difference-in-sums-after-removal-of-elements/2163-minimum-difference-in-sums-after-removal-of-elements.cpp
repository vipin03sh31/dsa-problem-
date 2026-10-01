class Solution {
  public:
    long long minimumDifference(vector<int> &nums) {
        int size = nums.size(), k = size / 3;
        vector<long long> pre(k + 1);
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long s = 0, r = LLONG_MAX;
        for (int i = 0; i < 2 * k; i++) {
            maxHeap.push(nums[i]);
            s += nums[i];
            if (maxHeap.size() > k) { s -= maxHeap.top(); maxHeap.pop(); }
            if (i >= k - 1) pre[i - k + 1] = s;
        }
        s = 0;
        for (int i = size - 1; i >= k; i--) {
            minHeap.push(nums[i]);
            s += nums[i];
            if (minHeap.size() > k) { s -= minHeap.top(); minHeap.pop(); }
            if (i <= 2 * k) r = min(r, pre[i - k] - s);
        }
        return r;
    }
};