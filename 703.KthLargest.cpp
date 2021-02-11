class KthLargest {
private:
        priority_queue<int,vector<int>,greater<int>> que;
        int kNum;
public:
    KthLargest(int k, vector<int>& nums) {
        kNum = k;
        for(auto n : nums){
            que.push(n);
            if(que.size() > k)
                que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size() > kNum)
            que.pop();
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
