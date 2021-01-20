class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> story; int j = 0;
        for(auto pu : pushed) {
            story.push(pu);
            while(!story.empty() && story.top() == popped[j]) {
                story.pop();
                ++j;
            }
        }
        return story.empty();
    }
};
