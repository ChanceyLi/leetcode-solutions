class Solution {
public:
    int longestSubstring(string s, int k) {
        int size = s.size();
        if(k <= 1) return size;
        if(s.empty() || k > size) return 0;
        vector<int> hash(128,0);
        for(char c : s) ++hash[c];
        int i = 0;
        while(i < size && hash[s[i]] >= k) ++i;
        if(i == size) return size;
        int l = longestSubstring(s.substr(0,i), k);
        while(i < size && hash[s[i]] < k) ++i;
        int r = longestSubstring(s.substr(i), k);
        return max(l,r);
    }
};
