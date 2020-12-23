class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> tmp(26,{0,0});
        for(int i = 0; i < s.length(); ++i) 
            if(!tmp[s[i] - 'a'].first)
                tmp[s[i] - 'a'].first = i + 1;//first用来记录第一个字母出现的位置(+1，避免为0)
            else tmp[s[i] - 'a'].second = 1;//second用来记录是否重复
        int res = INT_MAX;
        for(int i = 0; i < 26; ++i)
            if(!tmp[i].second && tmp[i].first)//如果不重复且字母出现
                res = min(res,tmp[i].first);
        if(res == INT_MAX) return -1;//如果res值不改变，返回-1
        return (res - 1);
    }
};
