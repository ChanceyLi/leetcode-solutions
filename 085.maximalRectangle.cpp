class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<int> ans(col,0);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) 
                ans[j] = matrix[i][j] == '1' ? ans[j] + 1 : 0;
            res = max(res, largestArea(ans));
        }
        return res;
    }
    int largestArea(vector<int> ans) {
        int n = ans.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> mono;
        for(int i = 0; i < n; ++i) {
            while(!mono.empty() && ans[mono.top()] >= ans[i]) {
                right[mono.top()] = i;
                mono.pop();
            }
            left[i] = mono.empty() ? -1 : mono.top();
            mono.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; ++i) 
            res = max(res, (right[i] - left[i] - 1) * ans[i]);
        return res;
    }
};
