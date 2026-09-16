class Solution {
public:
    const int MOD = 1e9+7;
    long long power(long long a, long long b){
        long long res=1; a%=MOD;
        while(b>0){
            if(b&1) res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }
    int numberOfSets(int n, int k) {
        long long N=n+k-1, K=2*k;
        if(K>N) return 0;
        long long num=1, den=1;
        for(int i=0;i<K;i++){
            num=num*((N-i)%MOD)%MOD;
            den=den*(i+1)%MOD;
        }
        return (int)(num*power(den,MOD-2)%MOD);
    }
};