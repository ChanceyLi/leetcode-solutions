class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count_zero = 0, simp = -1;
        for(auto n : nums) 
            if(n == 0)
                ++count_zero;
            else 
                if(simp != n) simp = n;
                else return false; 
        if(count_zero > 3) return true;
        return nums[4] - nums[count_zero] < 5;
    }
};
