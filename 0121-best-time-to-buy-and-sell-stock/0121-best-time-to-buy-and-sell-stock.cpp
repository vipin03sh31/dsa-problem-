class Solution {
public:
    void sloveusingRec(vector<int>& prices, int index, int &mini, int &maxProfit){   // changed
        if(index == prices.size()){                                                  // changed
            return;
        }
        mini = min(mini, prices[index]);                                             // changed
        maxProfit = max(maxProfit, prices[index] - mini);                            // changed
        sloveusingRec(prices, index + 1, mini, maxProfit);                           // changed
    }
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;                                                          // changed
        int ans = 0;                                                                 // changed
        sloveusingRec(prices, 0, mini, ans);                                         // changed
        return ans;
    }
};