class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<long>> res(m+1,vector<long>(n+1,0));
        for(int i = 0; i <= m; ++i)
            res[i][0] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) {
                if(j > i) continue;
                if(s[i - 1] == t[j - 1])
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                else res[i][j] = res[i - 1][j];
            }
        return res[m][n];
    }
};
