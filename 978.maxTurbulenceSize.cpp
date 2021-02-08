class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int tmp_max = 1, size = arr.size(), res = 1, gap = 0, bf_gap = 0;
        for(int i = 1; i < size; ++i) {
            gap = arr[i] - arr[i - 1];
            if(bf_gap == 0) bf_gap = -gap;
            if((gap < 0 && bf_gap > 0) || (gap > 0 && bf_gap < 0)) {
                ++tmp_max;
                bf_gap = gap;
            } else {
                if(!gap) tmp_max = 1;
                else tmp_max = 2;
                bf_gap = gap;
            }
            res = max(tmp_max, res);
        }
        return res;
    }
};
