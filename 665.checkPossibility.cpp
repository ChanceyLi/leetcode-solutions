class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size(), count = 0;
        for(int i = 0; i < size - 1 && count < 2; ++i) {
            if(nums[i] <= nums[i + 1]) continue;
            ++count;
            if(i >= 1 && nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
            else nums[i] = nums[i + 1];
        }
        return count < 2;
    }
};
