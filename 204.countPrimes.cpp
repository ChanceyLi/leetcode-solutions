#include <vector>
class Solution {
public:
    int countPrimes(int n) {
        vector<int> res(n + 1);
        if(n < 2) return 0;
        for(int i = 2; i < n; ++i)
            res[i] = 1;//标记2 - n - 1
        int count = 0;
        for(int i = 2; i < int(sqrt(n)) + 1; ++i) //之后的数已经被前面的数筛选过了，因此遍历到sqrt(n)
        /*
            例如： 0 ~ 100
                对于10 ~ 100 而言，假设取a = 50
                可以分解为 a = 2 * 25 , 5 * 10。因此50已经被 i=2 ，5筛选过了，不会到10才筛选
                任何数字都有这样的性质，因为不存在i > sqrt(n) 且 n = i * j，此时j比i 大
                （不然就在j的时候筛选了，所以按大小顺序排列）
        */
            if(res[i]) 
                for(int j = i * i; j < n; j += i) //前面2i,3i,...,(i - 1)i已经被筛选过，故不考虑
                    res[j] = 0;//取出质数后筛掉它的倍数
        for(int i = 2; i < n; ++i)
            count += res[i];
        return count;
    }
};
