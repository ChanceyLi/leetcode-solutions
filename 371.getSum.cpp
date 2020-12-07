class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        sum = a ^ b;//抑或操作等同于求和，不管进位
        carry = (uint32_t)(a & b) << 1;//与操作加左移1位等同于进位，不管和
        if(carry)   return getSum(sum, carry);//反复迭代
        return sum;
    }
};
