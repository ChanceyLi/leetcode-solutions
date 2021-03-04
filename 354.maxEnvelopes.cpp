class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> a, const vector<int> b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int size = envelopes.size();
        int res = 0;
        vector<int> vec(size,0);
        for(int i = 0; i < size; ++i) {
            vec[i] = 1;
            int tMax = 0;
            for (int j = 0; j < i; ++j) 
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) 
                    tMax = max(tMax, vec[j]);
            vec[i] = tMax + 1;
            res = max(vec[i], res);
        }
        return res;
    }
};
