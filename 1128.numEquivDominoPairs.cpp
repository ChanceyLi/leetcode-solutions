class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto& d : dominoes)//auto后加引用！
            if(d[0] > d[1]) swap(d[0], d[1]);
        vector<int> domi;
        for(auto d : dominoes) 
            domi.push_back(d[0] * 10 + d[1]);
        unordered_map<int,int> map;
        for(auto d : domi)
            ++map[d];
        int res = 0;
        for(unordered_map<int,int> :: iterator it = map.begin(); it != map.end(); ++it)
            res += combination(it -> second);
        return res;
    }
    int combination(int a) {
        if(a < 2) return 0;
        return (a * (a - 1)) >> 1;
    }
};
