class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0, t = 0, size = arr.size();
        while(t < k && i < size - 1) {
            if(arr[i] > arr[i + 1]) {
                ++t;
                arr[i + 1] = arr[i];
            } else t = 1;
            ++i;
        }
        return arr[i];
    }
};
