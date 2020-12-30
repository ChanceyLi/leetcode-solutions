/*class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        sort(stones.begin(), stones.end());
        while(size > 1) {
            int minus = stones[size - 1] - stones[size - 2];
            stones.pop_back();
            stones.pop_back();
            size -= 2;
            if(minus) {
                if(size == 0 || minus >= stones[size - 1])
                    stones.push_back(minus);
                else
                    stones.insert(stones.begin() + search(stones, minus), minus);
                ++size;
            }
        }
        if(size == 1) return stones[0];
        return 0;
    }
    int search(vector<int> stones, int minus) {
        int start = 0, end = stones.size() - 1;
        while(start <= end) {
            int mid = start + ((end - start) >> 1);
            if(stones[mid] > minus) 
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            if(a != b) pq.emplace(a-b);
        }
        return pq.empty()? 0 : pq.top();
    }
};
