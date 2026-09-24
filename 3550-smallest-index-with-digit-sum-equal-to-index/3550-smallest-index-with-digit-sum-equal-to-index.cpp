class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            int s = 0, x = nums[i];
            while (x) {
                s += x % 10;
                x /= 10;
            }
            if (s == i) return i;
        }
        return -1;
    }
};