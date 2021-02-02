class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.length();
        int res = 0, tmp_max = 0;
        for(int i = 0; i < size; ++i) {
            int use = k;
            for(int j = i + 1; j < size; ++j) {
                if(s[j] != s[i]) --use;
                if(use == -1) {
                    tmp_max = j - i;
                    break;
                }
            }
            if(use >= 0) tmp_max = min(size, size - i + use);
            res = max(res, tmp_max);
        }
        return res;
    }
};
