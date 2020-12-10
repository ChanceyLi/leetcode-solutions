class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> tmp(2,0);//存储五块和十块钱的个数
        for(int b : bills) {
            switch(b) {
                case 5:
                    ++tmp[0];
                    break;
                case 10:
                    if(tmp[0] == 0) return false;
                    --tmp[0];
                    ++tmp[1];
                    break;
                case 20:
                    if((tmp[0] == 0 || tmp[1] == 0) && tmp[0] < 3) return false;
                    if(tmp[1] > 0) {
                        --tmp[0];
                        --tmp[1];
                    } else
                        tmp[0] -= 3;
                    break;
            }
        }
        return true;
    }
};
