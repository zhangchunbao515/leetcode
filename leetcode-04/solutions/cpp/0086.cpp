class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode beforeHead(0);
    ListNode afterHead(0);
    ListNode* before = &beforeHead;
    ListNode* after = &afterHead;

    while (head) {
      if (head->val < x) {
        before->next = head;
        before = before->next;
      } else {
        after->next = head;
        after = after->next;
      }
      head = head->next;
    }

    after->next = NULL;
    before->next = afterHead.next;

    return beforeHead.next;
  };
};