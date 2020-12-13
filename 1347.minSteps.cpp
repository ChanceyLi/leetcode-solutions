class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> map;
        for(auto str : s)
            ++map[str];
        int count = 0;
        for(auto str : t)
            if(map[str] != 0) {
                --map[str];
                ++count;
            }
        return s.length() - count;
    }
};
/*
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        st = collections.Counter(s)
        count = 0
        for st_ in t :
            if st[st_] > 0 :
                st[st_] -= 1
                count += 1
        return (len(s) - count)
*/
