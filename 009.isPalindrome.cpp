class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int tmp = x; long newx = 0;
        while(x) {
            newx = 10 * newx + x % 10;
            x /= 10;
        }
        return newx == tmp;
    }
};
