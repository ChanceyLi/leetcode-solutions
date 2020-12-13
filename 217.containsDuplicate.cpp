class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto n : nums)
            if(map[n]) return true;
            else ++map[n];
        return false;
    }
};
/*
*class Solution:
*    def containsDuplicate(self, nums: List[int]) -> bool:
*       return len(set(nums)) != len(nums)
*/
