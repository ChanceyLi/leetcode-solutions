
/*
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        int a = num % 100;
        if(a < 26 && a > 9)
            return translateNum(num / 10) + translateNum(num / 100);
        return translateNum(num / 10);
    }
};
*/
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        int size = 0, tmp = num;
        while(num) {
            ++size;
            num /= 10;
        }
        vector<int> dp(size);
        dp[0] = 1;
        int m = tmp % 100;
        if(m < 26 && m > 9)
            dp[1] = 2;
        else dp[1] = 1;
        tmp /= 10;
        for(int i = 2; i < size; ++i) {
            int mod = tmp % 100;
            if(mod < 26 && mod > 9)
                dp[i] = dp[i - 1] + dp[i - 2];
            else dp[i] = dp[i - 1];
            tmp /= 10;
        }
        return dp[size - 1];
    }
};
