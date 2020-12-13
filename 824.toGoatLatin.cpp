class Solution {
public:
    string toGoatLatin(string S) {
        string str, res; int index = 1;
        for(auto s : S)
            if(s != ' ')
                str.push_back(s);
            else {
                if(str[0] != 'a' && str[0] != 'e' && str[0] != 'i' && str[0] != 'o' && str[0] != 'u' && str[0] != 'A' && str[0] != 'E' && str[0] != 'I' && str[0] != 'O' && str[0] != 'U') {
                    int tmp = str[0];
                    str.erase(str.begin());
                    str.push_back(tmp);
                }
                str.push_back('m');
                str.push_back('a');
                for(int i = 0; i < index; ++i)
                    str.push_back('a');
                res += str;
                res.push_back(' ');
                str = "";
                ++index;
            }
        if(str.length() > 0) {
            if(str[0] != 'a' && str[0] != 'e' && str[0] != 'i' && str[0] != 'o' && str[0] != 'u' && str[0] != 'A' && str[0] != 'E' && str[0] != 'I' && str[0] != 'O' && str[0] != 'U') {
                int tmp = str[0];
                str.erase(str.begin());
                str.push_back(tmp);
            }
            str.push_back('m');
            str.push_back('a');
            for(int i = 0; i < index; ++i)
                str.push_back('a');
            res += str;
        }
        return res;
    }
};
