class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size(), tmp_max = 0;
        for(int i = 0; i < k; ++i) tmp_max += cardPoints[i];//初始化
        if(k == size) return tmp_max;
        int res = tmp_max;
        for(int i = 0; i < k; ++i) {
            tmp_max += cardPoints[size - i - 1] - cardPoints[k - i - 1];
            res = max(res, tmp_max);
        }
        return res;
    }
};
