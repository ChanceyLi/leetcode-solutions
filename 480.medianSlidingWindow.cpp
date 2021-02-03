class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> set;
        int left = 0, right = 0, size = nums.size();
        vector<double> res;
        while(right < size) {
            set.insert(nums[right]);
            if(set.size() > k) {
                set.erase(set.lower_bound(nums[left]));
                ++left;
            }
            if(set.size() == k) {
                double tmp;
                if(k % 2) tmp = (double)(*next(set.begin(), k / 2));
                else tmp = ((double)(*next(set.begin(), k / 2)) + (double)(*next(set.begin(), k / 2 - 1))) / 2;
                res.push_back(tmp);
            }
            ++right;
        }
        return res;
    }
};
