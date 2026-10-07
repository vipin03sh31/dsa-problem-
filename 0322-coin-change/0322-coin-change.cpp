class Solution {
public:
    // int sloveusingrec(vector<int>& coins, int amount){
    //     //base case
    //     if(amount == 0){
    //         return 0;
    //     }

    //     //iss amount ko create krne k liye 
    //     // I willl try each and every coin
    //     int mini = INT_MAX;
    //     for(int i = 0; i < coins.size();i++){
    //         if(coins[i] <= amount){
    //             //valid case
    //             //maine ek coin use ker liya
    //             int recursionkaans = sloveusingrec(coins,amount-coins[i]);
    //             // recursionka ans can be valid or invalid 
    //             if (recursionkaans != INT_MAX){
    //                 // ek valid ans mila h
    //                 // it may or may not be a valid ans;
    //                 mini = min(mini,1+recursionkaans);


    //             }
    //         }
    //     }
    //     return mini;


    // }
    int sloveusingdp(vector<int>& coins, int amount,vector<int>&dp){
        //base case
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        //iss amount ko create krne k liye 
        // I willl try each and every coin
        int mini = INT_MAX;
        for(int i = 0; i < coins.size();i++){
            if(coins[i] <= amount){
                //valid case
                //maine ek coin use ker liya
                int recursionkaans = sloveusingdp(coins,amount-coins[i],dp);
                // recursionka ans can be valid or invalid 
                if (recursionkaans != INT_MAX){
                    // ek valid ans mila h
                    // it may or may not be a valid ans;
                    mini = min(mini,1+recursionkaans);
                    

                }
            }
        }
        dp[amount] = mini;
        return mini;


    }
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int>dp(n+1,-1);
        int ans = sloveusingdp(coins,amount,dp);
        if( ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
        
        
    }
};