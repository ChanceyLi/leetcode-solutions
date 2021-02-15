class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, tmp = 0;
        for(auto n : nums) 
            if(n) ++tmp;
            else {
                res = max(res, tmp);
                tmp = 0;
            }
        res = max(res, tmp);
        return res;
    }
};
