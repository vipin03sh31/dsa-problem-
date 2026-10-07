class Solution {
public:
    int slove(int n ){
        if(n == 0 || n == 1){
            return n;
        }
        int ans = slove(n-1) + slove(n-2);
        return ans;
    }
    int fib(int n) {
        int ans = slove(n);
        return ans;
    }
};