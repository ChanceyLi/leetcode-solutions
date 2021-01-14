class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int res = 0, size = A.size();
        vector<bool> ans(size,false);
        for(int i = 0; i < size; ++i) {
            res = (res % 5) * 2 + A[i];
            if(res % 5 == 0) ans[i] = true;
        }
        return ans;
    }
};
