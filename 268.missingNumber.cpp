/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] != n && nums[i] != i)//当当前数字位置不匹配并且不等于n时
                swap(nums[i],nums[nums[i]]);//将其匹配对位
        }
        for(int i = 0; i < n; ++i) 
            if(i != nums[i]) return i;//缺失的那个不对位
        return n;
    }
};*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();//保证所有数字成对出现，而缺失数字只有单个
        for(int i = 0; i < nums.size(); ++i)
            res ^= nums[i] ^ i;
        return res;
    }
};
