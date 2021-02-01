class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int sumA = 0, sumB = 0;
        for(auto a : A) sumA += a;
        for(auto b : B) sumB += b;
        int gap = (sumA - sumB) >> 1, index = 0;
        for(auto a : A) {
            while(a - B[index] > gap) ++index;
            if(a - B[index] == gap) return vector<int>{a, B[index]};            
        }
        return vector<int>{};
    }
};
