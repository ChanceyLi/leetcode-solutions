class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        set<string> res;
        for(int i = 0; i < words.size(); ++i) {
            string str="";
            for(int j = 0; j < words[i].length(); ++j)
                str += morse[words[i][j] - 'a'];
            if(!res.count(str)) res.insert(str);
        }
        return res.size();
    }
};
