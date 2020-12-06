class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //if(flowerbed.size() == 0) return false;
        if(n == 0) return true;
        if(flowerbed.size() == 1) return (n == 1 && flowerbed[0] == 0);
        int count = 0;
        if(flowerbed[0] == flowerbed[1] && flowerbed[0] == 0) {
            ++count;
            flowerbed[0] = 1;
        }
        for(int i = 1; i < flowerbed.size() - 1; ++i) {
            if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                ++count;
                flowerbed[i] = 1;
            } 
            //if(n <= count) return true;
        }
        if(flowerbed[flowerbed.size() - 2] == flowerbed[flowerbed.size() - 1] && flowerbed[flowerbed.size() - 1] == 0) {
            ++count;
            flowerbed[flowerbed.size() - 1] = 1;
        }
        return n <= count;
    }
};
