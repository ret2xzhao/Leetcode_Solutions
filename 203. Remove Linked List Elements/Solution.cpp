/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre->next != NULL) {
            if (pre->next->val == val) {
                ListNode *temp = pre->next;
                pre->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else {
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};