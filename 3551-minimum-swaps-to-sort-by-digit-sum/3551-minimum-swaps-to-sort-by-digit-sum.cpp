class Solution {
public:
    int sumofDigits(int a) {
        int sum = 0;
        while (a != 0) {
            int b = a % 10;
            sum += b;
            a = a / 10;
        }
        return sum;
    }
   int minSwaps(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    vector<pair<pair<int,int>,int>> v(n); // changed
    for (int i = 0; i < n; i++)
        v[i] = {{sumofDigits(nums[i]), nums[i]}, i}; // changed
    sort(v.begin(), v.end()); // changed
    vector<bool> vis(n); // changed
    for (int i = 0; i < n; i++) { // changed
        if (vis[i] || v[i].second == i) continue;
        int j = i, len = 0;
        while (!vis[j]) { vis[j] = 1; j = v[j].second; len++; }
        count += len - 1;
    }
    return count;
   }
};