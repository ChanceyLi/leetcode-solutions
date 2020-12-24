class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size(), count = 0;
        vector<int> cdy(size,1);
        for(int i = 1; i < size; ++i) 
            if(ratings[i] > ratings[i - 1])
                cdy[i] = cdy[i - 1] + 1;
        for(int i = size - 2; i >=0; --i) 
            if(ratings[i] > ratings[i + 1] && cdy[i] <= cdy[i + 1])
                cdy[i] = cdy[i + 1] + 1;
        for(int c : cdy)
            count += c;
        return count;
    }
};
