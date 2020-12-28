class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> sell(3, 0);
        vector<int> buy(3, INT_MIN);
        for(auto &ele : prices)
            for(int i = 1; i < 3; ++i) {
                buy[i] = max(buy[i], sell[i-1] - ele);
                sell[i] = max(sell[i], buy[i] + ele);
            }
        return sell[2];
    }
};
