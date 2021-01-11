class Solution {
public: 
    int father[100010];
    int find(int x) {
        return x == father[x] ? x : (father[x] = find(father[x]));
    }
    void merge(int x, int y) {
        father[find(x)] = find(y);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        string areastr[100010];
        int cnt[100010] = {0};
        for(int i = 0; i < n; ++i) father[i] = i;
        for(auto p : pairs) merge(p[1], p[0]);
        for(int i = 0; i < n; ++i)
            areastr[find(i)] += s[i];
        for(int i = 0; i < n; ++i)
            sort(areastr[i].begin(), areastr[i].end());
        for(int i = 0; i < n; ++i)
            s[i] = areastr[father[i]][cnt[find(i)]++];
        return s;
    }
};
