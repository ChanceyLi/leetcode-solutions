class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int newk = k % size;
        reverse(nums.begin(), nums.begin() + size - newk);
        reverse(nums.begin() + size - newk, nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }
};
