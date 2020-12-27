class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> ans_t;//存储t映射
        unordered_map<char,char> ans_s;//存储s映射
        int size = s.size();
        for(int i = 0; i < size; ++i)
            if(!ans_t[t[i]] && !ans_s[s[i]]) {//不存在映射则添加映射
                ans_t[t[i]] = s[i];
                ans_s[s[i]] = t[i];
            } else 
                if(ans_t[t[i]] != s[i] || ans_s[s[i]] != t[i]) return false;//映射出错则返回错误
        return true;
    }
};
