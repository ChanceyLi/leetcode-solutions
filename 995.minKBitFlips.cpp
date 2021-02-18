class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int size = A.size();
        vector<int> vec(size + 1,0);
        int s = 0, res = 0;
        for(int i = 0; i < size; ++i) {
            s += vec[i];
            if((s + A[i]) % 2 == 0) {
                if(i + K > size) return -1;
                ++vec[i];
                --vec[i + K];
                ++s;
                ++res;
            }
        }
        return res;
    }
};
