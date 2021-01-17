class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        double diff;
        for(int i = 1; i < size; ++i) {
            double tmp;
            if(coordinates[i][1] == coordinates[i - 1][1])
                tmp = DBL_MAX;
            else
                tmp = (double)(coordinates[i][0] - coordinates[i - 1][0]) / (coordinates[i][1] - coordinates[i - 1][1]);
            if(i == 1) diff = tmp;
            if(diff != tmp) return false;
        }
        return true;
    }
};
