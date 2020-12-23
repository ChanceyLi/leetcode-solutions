class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> tmp(26,{0,0});
        for(int i = 0; i < s.length(); ++i) {
            if(tmp[s[i] - 'a'].first == 0)
                tmp[s[i] - 'a'].first = i + 1;
            else tmp[s[i] - 'a'].second = 1;
        }
        int res = INT_MAX;
        for(int i = 0; i < 26; ++i)
            if(!tmp[i].second)
                res = min(res,tmp[i].first);
        return res - 1;
    }
};
