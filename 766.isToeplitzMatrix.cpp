class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
/*        int row = matrix.size(), column = matrix[0].size();
        for(int i = 0; i < column - 1; ++i) {
            int tmp = matrix[0][i];
            for(int j = 1; j < row && j < column - i; ++j)
                if(matrix[j][j + i] != tmp)
                    return false;
        }
        for(int i = 1; i < row - 1; ++i) {
            int tmp = matrix[i][0];
            for(int j = 1; j < column && j < row - i; ++j)
                if(matrix[j + i][j] != tmp)
                    return false;
        }
        return true;
*/
        int row = matrix.size();
        vector<int> tmp = matrix[0];
        for(int i = 1; i < row; ++i) {
            tmp.pop_back();
            tmp.insert(tmp.begin(), matrix[i][0]);
            if(tmp != matrix[i]) return false;
        }
        return true;
    }
};
