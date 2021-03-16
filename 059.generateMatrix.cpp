class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int i = 0, j = 0, di = 0, dj = 1;
        for(int k = 1; k <= n*n; ++k) {
            res[i][j] = k;
            if(res[(i + di + n) % n][(j + dj + n) % n] != 0) {
                int tmp = di;
                di = dj;
                dj = -tmp;
            }
            i = (i + di) % n;
            j = (j + dj) % n;
        }
        return res;
    }
};
