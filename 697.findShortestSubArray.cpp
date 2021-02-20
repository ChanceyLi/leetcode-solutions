class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> vcn(50000, 0);
        for(auto n : nums) ++vcn[n];
        int _max = 0;
        for(auto n : vcn) 
            if(n) _max = max(_max, n);
        vector<int> maxn;
        for(int i = 0; i < 50000; ++i)
            if(vcn[i] == _max) maxn.push_back(i);
        int res = INT_MAX;
        for(auto n : maxn) {
            int left = 0, right = 0;
            for(int i = 0; i < nums.size(); ++i) 
                if(nums[i] == n) {
                    left = i;
                    break;
                }
            for(int i = nums.size() - 1; i >= 0; --i)
                if(nums[i] == n) {
                    right = i;
                    break;
                }
            res = min(res, right - left + 1);
        }
        return res;
    }
};
