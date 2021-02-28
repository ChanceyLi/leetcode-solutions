class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() <= 2) return true;
        for(int i = 0; i < A.size() - 1; ++i)
            if(A[i] <= A[i + 1]) {
                if(i == A.size() - 2) return true;
                continue;
            } else break;
        for(int i = 0; i < A.size() - 1; ++i)
            if(A[i] >= A[i + 1]) {
                if(i == A.size() - 2) return true;
                continue;
            } else break;
        return false;
    }
};
