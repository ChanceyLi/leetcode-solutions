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
    ListNode* partition(ListNode* head, int x) {
       ListNode *min_x = new ListNode(-1), *max_x = new ListNode(-1);
       ListNode *p1 = min_x, *p2 = max_x;
       while(head){
           if(head -> val < x){
               p1 -> next = head;
               p1 = p1 -> next;
           }else{
               p2 -> next = head;
               p2 = p2 -> next;
           }
           head = head -> next;
       }
       p2 -> next = nullptr;
       p1 -> next = max_x -> next;
       return min_x -> next;
    }
};
