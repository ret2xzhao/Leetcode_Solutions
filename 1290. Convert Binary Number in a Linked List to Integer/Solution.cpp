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
    int getDecimalValue(ListNode* head) {
        ListNode* current;
        current = head;
        int count = 0;
        while(current != NULL) {
            ++count;
            current = current->next;
        }
        current = head;
        int result = 0;
        while(count != 0) {
            result = result + (current->val) * pow(2, count-1);
            --count;
            current = current->next;
        }
        return result;
    }
};
