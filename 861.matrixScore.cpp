class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        for(int i = 0; i < r; ++i)//行变换翻转第一列全为1
            if(A[i][0] == 0)
                for(int j = 0; j < c; ++j)
                    A[i][j] ^= 1;
        for(int j = 1; j < c; ++j) {//列变换翻转尽可能多的1
            int count_r = 0;
            for(int i = 0; i < r; ++i)
                if(A[i][j] == 1)
                    ++count_r;
            if(2 * count_r < r)
                for(int i = 0; i < r; ++i)
                    A[i][j] ^= 1;
        }
        int res = 0;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                res += A[i][j] << (c - j - 1);
        return res;
    }
};
