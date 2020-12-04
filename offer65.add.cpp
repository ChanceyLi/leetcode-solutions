class Solution {
public:
    int add(int a, int b) {
        uint32_t res = 0;//负数→移位会补1，为了防止补1，将涉及移位的数都定义为uint32_t
        int count = 0, sum = 0;//count表示进位，sum表示当前位
        uint32_t newa = a, newb = b;
        uint32_t i = 0xffffffff;//循环次数
        while(i) {
            i >>= 1;
            if(newa & 1 && newb & 1)
                count = 1;
            else 
                if(newa & 1 || newb & 1)
                    if(sum == 0) 
                        sum = 1;
                    else {
                        count = 1;
                        sum = 0;
                    }
            res =(sum << 31) ^ (res >> 1);//将最大位赋值并向后移，保证数据顺序
            newa >>= 1;
            newb >>= 1;
            sum = count;
            count = 0;
            //cout<<res<<" ";
        }       
        return res;
    }
};
