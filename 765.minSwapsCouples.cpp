class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        for(int i = 0; i < row.size(); i += 2) 
            if(row[i + 1] != find_another(row[i])) {
                int tmp = find_index(row, find_another(row[i]));
                swap(row[i + 1], row[tmp]);
                ++res;
            }
        return res;
    }
    int find_another(int n) {
        return n % 2 == 0 ? n + 1 : n - 1;
    }

    int find_index(vector<int>& row, int n) {
        for(int i = 0; i < row.size(); ++i) 
            if(row[i] == n) return i;
        return -1;
    }
};
