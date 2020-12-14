class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> temp;
        for(auto s : strs){
            string tmp = s;
            sort(s.begin(),s.end());//排序的使用方法
            temp[s].push_back(tmp);
        }
        vector<vector<string>> res;
        for(auto it = temp.begin(); it != temp.end(); it++){
            res.push_back(it -> second);
        }
        return res;
    }
};
