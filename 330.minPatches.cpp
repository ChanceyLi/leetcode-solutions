class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0, size = nums.size(), res = 0;
        long jump = 1;
        while(jump <= n) {
            if(index < size && nums[index] <= jump) {
                jump += nums[index];
                ++index;
            } else {
                jump <<= 1;
                ++res;
            }
        }
        return res;
    }
};
