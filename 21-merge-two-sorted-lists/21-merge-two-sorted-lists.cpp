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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr1 -> val < ptr2 -> val) {
                ListNode* node = new ListNode(ptr1 -> val);
                temp -> next = node;
                temp = temp -> next;
                ptr1 = ptr1 -> next;
            }
            else if(ptr1 -> val > ptr2 -> val) {
                ListNode* node = new ListNode(ptr2 -> val);
                temp -> next = node;
                temp = temp -> next;
                ptr2 = ptr2 -> next;
            }
            else {
                ListNode* node1 = new ListNode(ptr2 -> val);
                ListNode* node2 = new ListNode(ptr2 -> val);
                temp -> next = node1;
                temp = temp -> next;
                temp -> next = node2;
                temp = temp -> next;
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        
        while(ptr1 != NULL) {
            ListNode* node = new ListNode(ptr1 -> val);
            temp -> next = node;
            temp = temp -> next;
            ptr1 = ptr1 -> next;
        }
        
        while(ptr2 != NULL) {
            ListNode* node = new ListNode(ptr2 -> val);
            temp -> next = node;
            temp = temp -> next;
            ptr2 = ptr2 -> next;
        }
        
        return dummy -> next;
    }
};