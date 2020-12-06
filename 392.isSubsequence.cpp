class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(auto str : t) {
            if(s[index] == str) 
                ++index;
            if(index == s.length())
                return true;
        }
        return index == s.length();
    }
};
