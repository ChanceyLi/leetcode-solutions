/*class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        bool flag = false;
        while(n) {
            if(flag && n % 2 == 1) 
                return false;       
            if(n % 2 == 1) 
                flag = true;
            n >>= 1;                  
        }
        return true;
    }
};*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & n - 1);
    }
};
