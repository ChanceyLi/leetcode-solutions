class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        if(size1 > size2) return false;
        vector<int> map1(26,0);
        vector<int> map2(26,0);
        for(int i = 0; i < size1; ++i) {
            ++map1[s1[i] - 'a'];
            ++map2[s2[i] - 'a'];
        }
        for(int i = 0; i < size2 - size1; ++i) {
            if(map1 == map2) return true;
            --map2[s2[i] - 'a'];
            ++map2[s2[i + size1] - 'a'];
        }
        return map1 == map2;
    }
};
