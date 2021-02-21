class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> _max, _min;
        int left = 0, right = 0, res = 0, size = nums.size();
        while(right < size) {
            while(!_max.empty() && nums[_max.back()] >= nums[right]) _max.pop_back();
            while(!_min.empty() && nums[_min.back()] <= nums[right]) _min.pop_back();

            _max.push_back(right);
            _min.push_back(right);

            while(abs(nums[_max.front()] - nums[_min.front()]) > limit) {
                ++left;
                if(!_max.empty() && _max.front() < left) _max.pop_front();
                if(!_min.empty() && _min.front() < left) _min.pop_front();
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
    }
};
