class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int size = rains.size();
        unordered_map<int,int> map;
        vector<int> res(size, 1);
        set<int> q;
        for(int i = 0; i < size; ++i) {
            int tmp = rains[i];
            if(!tmp) q.insert(i);
            else {
                if(map.find(tmp) != map.end()) {
                    auto p = q.lower_bound(map[tmp]);
                    if(p == q.end()) return {};
                    res.at(*p) = tmp;
                    q.erase(p);
                }
                map[tmp] = i;
                res.at(i) = -1;
            }
        }
        return res;
    }
};
