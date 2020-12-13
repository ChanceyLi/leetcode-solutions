class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head) {
            res = (res << 1) + head -> val;
            head = head -> next;
        }
        return res;
    }
};
/*
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        while head :
            res = (res << 1) + head.val
            head = head.next
        return res
*/