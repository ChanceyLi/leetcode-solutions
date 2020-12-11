class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0, d = 0;//表示两种议员失效的个数，并当出现相应议员时丢弃并减一
        while(!senate.empty()) {
            string s;//新创建一轮后仍然存活的议员
            for(auto str : senate) {
                if(str == 'R') {
                    if(r)   --r;//丢弃
                    else {
                        s.push_back(str);
                        ++d;//使得d方议员失效个数加一
                    }      
                }else{ 
                    if(d)   --d;
                    else {
                        s.push_back(str);
                        ++r;
                    }   
                }
            }
            if(senate == s) return s[0] == 'R' ? "Radiant" : "Dire";//字符串不变时表示已经投票失效完成，在场必然都是一个阵营
            senate = s;
        }
        return "";
    }
};
