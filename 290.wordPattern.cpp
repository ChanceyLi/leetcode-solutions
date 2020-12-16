class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int index = 0;
        unordered_map<char,string> map;//双向对应，所以用两个hash表
        unordered_map<string,char> map_;
        for(int i = 0; i < pattern.length(); ++i) {
            string substring;
            while(index < s.length() && s[index]!=' ') {
                substring.push_back(s[index]);
                ++index;
            }
            if(substring == "") return false;//细节
            ++index;
            if(map[pattern[i]] == "")    
                map[pattern[i]] = substring;
            else {
                if(map[pattern[i]] != substring)    
                    return false;
            }
            if(!map_[substring])    
                map_[substring] = pattern[i];
            else {
                if(map_[substring] != pattern[i])    
                    return false;
            }
        }
        if(index < s.length() - 1 || s[s.length() - 1] == ' ') return false;//细节
        return true;
    }
};
