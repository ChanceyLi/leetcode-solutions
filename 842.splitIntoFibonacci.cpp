class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        splitFibonacci(S,0,res);
        return res;
    }
    bool splitFibonacci(string S, int index, vector<int>& list) {
        if(index == S.length()) return list.size() > 2;
        for(int i = index + 1; i <= S.length(); ++i) {
            if((S[index] == '0' && i > index + 1) || (i - index > 10))
                break;
            long temp = 0;
            for(int j = index; j < i; ++j) {
                temp = temp * 10 + (S[j] - '0');
                if(temp > INT_MAX) break;//越界就直接break出来
            }
            int one = list.size() > 1 ? list[list.size() - 1] : -1;
            int two = list.size() > 1 ? list[list.size() - 2] : -1;
            long sum = (long)one + two;
            if(sum < INT_MIN || sum > INT_MAX) break;//防止加法越界
            list.push_back(temp);
            if((one == -1 || two == -1 || one + two == temp) && splitFibonacci(S, i, list)) 
                return true;
            list.pop_back();
        }
        return false;
    }
};
