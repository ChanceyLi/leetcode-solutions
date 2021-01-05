class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = 0, end = 0;
        vector<vector<int>> positions;
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == s[i - 1]) {
                end = i;
            } else {
                if(end - start > 1) positions.push_back({start,end});
                start = i;
                end = i;
            }
        }
        if(end - start > 1) positions.push_back({start,end});
        return positions;
    }
};
