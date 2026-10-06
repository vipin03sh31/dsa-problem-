class Solution {
public:
void pushelement(vector<int>&ans,int element){
    if(element == 0){
        return;
    }
    int n = element %10;
    pushelement(ans,element/10);
    ans.push_back(n);

}
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i <nums.size(); i++){
            int element = nums[i];
            pushelement(ans,element); 
        }
        return ans;

        
    }
};