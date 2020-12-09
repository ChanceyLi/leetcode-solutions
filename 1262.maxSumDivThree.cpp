/*class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums)
            sum += n;
        int mod = sum % 3;
        if(mod == 0) return sum;
        vector<pair<int,int>> newnums;
        for(auto n : nums)
            if(n % 3)
                newnums.push_back({n % 3, n});
        sort(newnums.begin(), newnums.end(), [](const pair<int,int> lhs, const pair<int,int> rhs){
            return lhs.second < rhs.second;
        });

        int find1 = INT_MAX, find2 = INT_MAX, find3 = INT_MAX;
        for(int i = 0; i < newnums.size(); ++i)
            if(newnums[i].first == mod) {
                find1 = newnums[i].second;
                break;
            }
        for(int i = 0; i < newnums.size(); ++i)
            if(newnums[i].first == 3 - mod) 
                if(find2 == INT_MAX) {
                    find2 = newnums[i].second;
                    find3 = INT_MAX;
                }
                else {
                    find2 += newnums[i].second;
                    find3 = 0;
                    break;
                }
        if (find1 == INT_MAX && find3 == INT_MAX) return 0; 
        if(find3 == INT_MAX) return sum - find1;
        return sum - min(find1, find2);    
    }
};*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0,INT_MIN, INT_MIN};
        for(int a : nums) {
            vector<int> dp2 = {0, 0, 0};
            for(int i = 0; i < 3; ++i)
                dp2[(i + a) % 3] = max(dp[(i + a) % 3], dp[i] + a);
            dp = dp2;
        }   
        return dp[0];
    }
};
