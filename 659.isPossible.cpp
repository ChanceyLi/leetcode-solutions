class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> countmap;//存储数字次数
        unordered_map<int,int> endmap;//存储连续序列结尾数字次数
        for(auto n : nums)
            ++countmap[n];//初始化
        for(auto n : nums) {
            if(countmap[n] > 0)//仍有剩余数字时进行判断
                if(endmap[n - 1] > 0) {//前数字序列存在，则添加进去
                --endmap[n - 1];
                ++endmap[n];
                --countmap[n];
                } else {//不存在则新建序列，判断是否可以构成三个数字组成的序列
                    if(countmap[n + 1] > 0 && countmap[n + 2] > 0) {//可以构成
                    ++endmap[n + 2];
                    --countmap[n];
                    --countmap[n + 1];
                    --countmap[n + 2];
                    } else 
                        return false;
                }
        }
        return true;
    }
};
