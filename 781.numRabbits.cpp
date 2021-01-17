class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(!answers.size()) return 0;
        sort(answers.begin(), answers.end());
        int size = answers.size();
        int num = answers[0], start = 0, res = 0;
        for(int i = 1; i < size; ++i) {
            if(num != answers[i]) {
                int pow = (i - start) / (num + 1);
                int mod = (i - start) % (num + 1);
                res += (pow + (mod != 0)) * (num + 1);
                num = answers[i];
                start = i;
            }
        }
        int pow = (size - start) / (num + 1);
        int mod = (size - start) % (num + 1);
        res += (pow + (mod != 0)) * (num + 1);
        return res;
    }
};
