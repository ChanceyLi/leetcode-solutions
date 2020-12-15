class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> tmp;
        while(N) {
            tmp.push_back(N % 10);
            N /= 10;
        }
        if(tmp.size() < 2) return N;
        for(int i = 0; i < tmp.size() - 1; ++i) {
            if(tmp[i] < tmp[i + 1]) {
                --tmp[i + 1];
                for(int j = 0; j <= i; ++j)
                    tmp[j] = 9;
            }
        }
        int res = 0, count = 1;
        for(int i = 0; i < tmp.size(); ++i) {
            res = res + tmp[i] * count;
            count *= 10;
        }
        return res;
    }
};
