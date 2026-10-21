class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int>freq;
        for(int i = 0; i< nums.size();i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]]++;
                count++;
            }
            else{
                nums.erase(nums.begin() + i);
                i--;  
            }
        }
        return count;
        
    }
};