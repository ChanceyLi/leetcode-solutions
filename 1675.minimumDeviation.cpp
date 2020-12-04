class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int min_num = INT_MAX;
/*
奇数只能乘2一次，而偶数可以一直除2直到变成奇数！
所以先将奇数都乘2，之后在逐步将最大值除2取最小差值
*/
        for(auto& n : nums) {
            if(n % 2)
                n *= 2;
            q.push(n);
            min_num = min(n,min_num);
        }
        int res = INT_MAX;
        while(q.top() % 2 == 0) {//最大值变成奇数表示没有优化空间了！
            int new_max = q.top() / 2;
            q.pop();
            q.push(new_max);
            min_num = min(min_num,new_max);
            res = min(q.top() - min_num, res);
        }
        return res;
    }
};
