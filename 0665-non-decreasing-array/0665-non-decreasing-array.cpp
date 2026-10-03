class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(i < 2 || nums[i-2] <= nums[i] ){ // changed
                    nums[i-1] = nums[i];
                }
                else {
                    nums[i] = nums[i-1];
                }
            }
        }
        if( count >1){
            return false;
        }
        else {
            return true;
        }
        
    }
};