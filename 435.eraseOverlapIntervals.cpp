class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(!size) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> lhs, vector<int> rhs) {
            if(lhs[1] == rhs[1]) return lhs[1] > rhs[1];//起点逆序
            return lhs[1] < rhs[1];//终点顺序
        });
        int value = intervals[0][1], count = 0;
        for(int i = 1; i < size; ++i) 
            if(intervals[i][0] < value) ++count;
            else value = intervals[i][1];
        return count;
    }
};
