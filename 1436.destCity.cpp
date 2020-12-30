/*class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string tmp = paths[0][1]; 
        bool flag = true;
        while(flag) {//O(n^2)
            flag = false;
            for(auto n : paths) 
                if(tmp == n[0]) {
                    flag = true;
                    tmp = n[1];
                    break;
                } 
        }
        return tmp;
    }
};*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto p : paths) s.insert(p[0]);
        for(auto p : paths) 
            if(s.find(p[1]) == s.end())
                return p[1];
        return "";
    }
};
