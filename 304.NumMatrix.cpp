class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return;//空示例必须，我人傻了
        int row = matrix.size(), col = matrix[0].size();
        sums = vector<vector<int>>(row + 1,vector<int>(col + 1,0));//size增大，减少判断！
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + matrix[i][j];             
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        res = sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
