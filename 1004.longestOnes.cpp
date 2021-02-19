class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, size = A.size();
        int count = 0;
        while(right < size) {
            if(!A[right]) ++count;
            ++right;
            if(count > K) {
                if(!A[left]) --count;
                ++left;
            }
        }
        return right - left;
    }
};
