class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size(), sum = 0;
        for(int i = 0; i < k; ++i) sum += nums[i];
        int res = sum;
        for(int i = 0; i < size - k; ++i) {
            sum += nums[i + k] - nums[i];
            res = max(sum, res);
        }
        return (double)res/k;
    }
};
