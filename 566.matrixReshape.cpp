class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int col = nums.size(), row = nums[0].size();
        if(col * row != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < col * row; ++i)
            ans[i / c][i % c] = nums[i / row][i % row];
        return ans;
    }
};
