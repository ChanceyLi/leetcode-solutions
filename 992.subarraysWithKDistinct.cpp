class Solution {
public:
    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int,int> map;
        int left = 0, right = 0, size = A.size();
        int res = 0;
        while(right < size) {
            ++map[A[right++]];
            while((int)map.size() > K) {
                --map[A[left]];
                if(map[A[left]] == 0) map.erase(A[left]);
                ++left;
            }
            res += right - left;
        } 
        return res;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A,K) - GetMostDistinct(A,K-1);
    }
};
