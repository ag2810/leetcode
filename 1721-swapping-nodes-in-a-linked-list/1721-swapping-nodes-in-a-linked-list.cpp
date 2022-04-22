/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i = 1;i < k;i++) {
            fast = fast -> next;
        }
        
        ListNode* slow = head;
        ListNode* ptr = fast -> next;
        while(ptr) {
            slow = slow -> next;
            ptr = ptr -> next;
        }
        swap(fast -> val, slow -> val);
        
        return head;
    }
};