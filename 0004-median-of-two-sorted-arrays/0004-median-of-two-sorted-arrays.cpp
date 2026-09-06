class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int i = 0;
        while(i < nums2.size()){
            nums1.push_back(nums2[i]);
            i++;
        }
        sort(nums1.begin(),nums1.end());

        if( nums1.size()%2 == 0){
            int a = nums1.size()/2;
            ans = ((double)nums1[a-1] + (double)nums1[a])/2;
            return ans;
            
        } 
        else{
            int b = nums1.size()/2;
            
            return (double)nums1[b];
        }
        
    }
};