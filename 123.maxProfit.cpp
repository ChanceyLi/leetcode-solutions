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
/*
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        INT_MIN = -2147483648
        sell=[0,0,0]
        buy =[INT_MIN,INT_MIN,INT_MIN]
        for ele in prices:
            for i in range(1,3,1):
                buy[i] = max(buy[i], sell[i - 1] - ele)
                sell[i] = max(sell[i], buy[i] + ele)
        return sell[2]
*/
