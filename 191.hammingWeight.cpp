class Solution {
public:
    int hammingWeight(uint32_t n) {
      int res = 0;
      for(int i = 0; i < 32; ++i) {
          res += (n % 2);
          n >>= 1;
      }  
      return res;
    }
};
/*
Python:
class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        for i in range(32):
            res += n % 2
            n >>= 1
        return res
*/
