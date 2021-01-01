class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0) return -1;
        int res = 1;
        for(int i = 1; i % K != 0; ++res) {
            i %= K;
            i = 10 * i + 1;
        }
        return res;
    }
};
