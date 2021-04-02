class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, size = height.size();
        if(!size) return 0;
        vector<int> leftMAX(size, 0), rightMAX(size, 0);
        leftMAX[0] = height[0];
        rightMAX[size - 1] = height[size - 1];
        for(int i = 1; i < size; ++i)
            leftMAX[i] = max(height[i], leftMAX[i - 1]);
        for(int j = size - 2; j >= 0; --j)
            rightMAX[j] = max(height[j], rightMAX[j + 1]);
        for(int i = 0; i < size; ++i)
            res += min(leftMAX[i], rightMAX[i]) - height[i];
        return res;
    }
};
