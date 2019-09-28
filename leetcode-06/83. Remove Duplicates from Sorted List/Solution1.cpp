// Description:
// Given a sorted linked list,
// delete all duplicates such that each element appear only once.

// Example 1:
// Input: 1->1->2
// Output: 1->2

// Example 2:
// Input: 1->1->2->3->3
// Output: 1->2->3


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head, *q = head->next;
        while (p && q) {
            if (p->val == q->val) {
                p->next = q->next;
                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};