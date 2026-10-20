class Solution {
public:
    int sumOfDigits(int a){
        int sum = 0;
        while(a != 0){
            int b = a%10;
            sum += b;
            a = a/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i <nums.size();i++){
            int a = nums[i];
            mini = min(mini,sumOfDigits(a));

        }
        return mini;
        
    }
};