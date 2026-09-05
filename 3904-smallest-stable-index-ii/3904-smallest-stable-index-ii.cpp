class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for(int j = n-2; j >= 0; j--){
            suffixMin[j] = min(suffixMin[j+1], nums[j]);
        }

        int maxa = INT_MIN;
        for(int i = 0; i < n; i++){
            maxa = max(maxa, nums[i]);
            int mina = suffixMin[i];
            if(maxa - mina <= k){
                return i;
            }
        }
        return -1;
    }
};