class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int countCutm = 0, size = customers.size();
        for(int i = 0; i < size; ++i) 
            if(grumpy[i] == 0) countCutm += customers[i];
        for(int i = 0; i < X; ++i) 
            if(grumpy[i] == 1) countCutm += customers[i];
        int maxCutm = countCutm;
        for(int i = 0; i < size - X; ++i) {
            countCutm = countCutm + (grumpy[i + X] == 1 ? customers[i + X] : 0) - (grumpy[i] == 1 ? customers[i] : 0);
            maxCutm = max(maxCutm, countCutm);
        }
        return maxCutm;
    }
};
