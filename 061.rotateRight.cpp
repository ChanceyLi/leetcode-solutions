/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int mod = 1;
        ListNode* start = head, *end = head;
        while(end -> next) {
            end = end -> next;
            ++mod;
        }
        k = mod - k % mod;
        end -> next = head;
        for(int i = 0; i < k - 1; ++i)
            start = start -> next;
        ListNode * tmp = start -> next;
        start -> next = nullptr;
        return tmp;
    }
};
