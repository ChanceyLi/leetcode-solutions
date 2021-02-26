class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int psize = puzzles.size();
        unordered_map<int,int> map;
        vector<int> res(psize);
        for(auto &w : words) {
            int mask = 0;
            for(auto s : w)
                mask |= (1 << (s - 'a'));
            ++map[mask];
        }
        for(int i = 0; i < psize; ++i) {
            string &w = puzzles[i];
            int mask = 0;
            for(auto c : w) 
                mask |= 1 << (c - 'a');
            for(int s = mask; s; --s &= mask)
                if(s & (1 << (w[0] - 'a')) && map.count(s))
                    res[i] += map[s];
        }
        return res;

    }
};
