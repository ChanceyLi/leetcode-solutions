class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int size = nums.size();
        int l = 0, r = 0;
        while(r < size) {
            if(r + 1 < size && nums[r] + 1 == nums[r + 1]) {
                ++r;
                continue;
            }
            if(l != r) res.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            else res.push_back(to_string(nums[l]));
            l = ++r;
        }
        return res;
    }
};
