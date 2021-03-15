class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return vector<int>{};
        vector<int> res;
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = 0, di = 0, dj = 1;
        for(int k = 0; k < r * c; ++k) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
            if(matrix[(i + di + r) % r][(j + dj + c) % c] == INT_MAX) {
                int tmp = di;
                di = dj;
                dj = -tmp;
            }
            i = (i + di) % r;
            j = (j + dj) % c;
        }
        return res;
    }
};
