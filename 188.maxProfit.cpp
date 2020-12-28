/*class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<pair<int,int>> ans;
        int psize = prices.size();
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < psize; ++i) {
            if(low == INT_MAX) {
                low = prices[i];
            } else {
                if(low > prices[i] && high == INT_MIN)
                    low = prices[i];
                if(high <= prices[i])
                    high = prices[i];
                else {
                    ans.push_back({low,high});
                    low = INT_MAX;
                    high = INT_MIN;
                }
            } 
        }
        if(low != INT_MAX && high != INT_MIN)
            ans.push_back({low,high});
        int asize = ans.size();
        int res = 0;
        int minu = INT_MAX;
        vector<pair<int,double>> gap;
        for(int i = 0; i < asize; ++i) {
            int tmp = ans[i].second - ans[i].first;
            gap.push_back({tmp,i});
            res += tmp;
        } 
        if(k < asize) {
            for(int i = 0; i < asize - 1; ++i) {
                gap.push_back({ans[i].second - ans[i + 1].first, (double)i + 0.5});
            }
            sort(gap.begin(),gap.end(), [](const pair<int,double> lhs, const pair<int,double> rhs){
                return lhs.first < rhs.first;
            });
            int start = 0;
            while(start < gap.size()){
                set<double> ext;
                int minus = 0, index = 0, ind = start;
                while(index < asize - k) {
                    if(ind >= gap.size()) break;
                    if(ext.find(gap[ind].second) == ext.end()) {
                        minus += gap[ind].first;
                        ++index;    
                        ext.insert(gap[ind].second + 0.5);
                        ext.insert(gap[ind].second - 0.5);
                    }
                    ++ind;
                }
                if(index == asize - k) 
                    minu = min(minu,minus); 
                ++start;         
            }  
        }
        return res - minu;
    }
};*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> sell(k + 1, 0);
        vector<int> buy(k + 1, INT_MIN);
        for(auto &ele:prices)
            for(int i = 1; i < k + 1; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - ele);
                sell[i] = max(sell[i], buy[i] + ele);
            }
        return sell[k];
    }
};
