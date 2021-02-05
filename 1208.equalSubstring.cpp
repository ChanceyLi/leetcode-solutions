class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int size = s.size();
        int cost = 0, left = 0, res = 0;
        for(int i = 0; i < size; ++i) {
            cost += abs(s[i] - t[i]);
            while(cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
