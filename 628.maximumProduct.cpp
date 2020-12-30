class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for(auto n : nums) {
            if(n >= max3) 
                if(n >= max2) {
                    max3= max2;
                    if(n >= max1) {
                        max2 = max1;
                        max1 = n;
                    } else 
                        max2 = n;
                } else max3 = n;
            if(n <= min2) 
                if(n <= min1) {
                    min2 = min1;
                    min1 = n;
                } else 
                    min2 = n;
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};
