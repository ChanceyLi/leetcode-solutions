class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
            while(g[i] > s[j]) {
                if(j == s.size() - 1)
                    return i;
                ++j;
            }
            ++j;
            ++i;
        }
        return i;
    }
};
