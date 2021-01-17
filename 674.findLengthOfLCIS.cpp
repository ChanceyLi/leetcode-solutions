class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int res = 1, tmp = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1]) ++tmp;
             else tmp = 1;
            res = max(res, tmp);
        }
        return res;
    }
};
