class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(!nums.size()) return 0;
        int res = 1, index = 1;
        bool mod;//true表示上升，false表示下降
        while(index < nums.size() && nums[index] ==nums[index - 1]) ++index;//过滤数字前方相同的序列
        if(index >= nums.size()) return 1;//越界返回1
        if(nums[index] > nums[index - 1]) mod = true;//初始化mod
        else mod = false;
        ++res;
        for(int i = index + 1; i < nums.size(); ++i) {//改变状态时++res
            if(nums[i] < nums[i - 1] && mod) {
                mod = false;
                ++res;
            }
            if(nums[i] > nums[i - 1] && !mod) {
                mod = true;
                ++res;
            }
        }
        return res;
    }
};
