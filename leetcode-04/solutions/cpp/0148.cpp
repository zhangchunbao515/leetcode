class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    ListNode dummy(0);
    dummy.next = head;

    for (int k = 1; k < length; k <<= 1) {
      ListNode* curr = dummy.next;
      ListNode* tail = &dummy;
      while (curr) {
        ListNode* l = curr;
        ListNode* r = split(l, k);
        curr = split(r, k);
        vector<ListNode*> merged = merge(l, r);
        tail->next = merged[0];
        tail = merged[1];
      }
    }

    return dummy.next;
  }

 private:
  ListNode* split(ListNode* head, int k) {
    while (--k && head) head = head->next;
    ListNode* rest = head ? head->next : NULL;
    if (head) head->next = NULL;
    return rest;
  }

  vector<ListNode*> merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
      if (l1->val > l2->val) swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    while (tail->next) tail = tail->next;

    return {dummy.next, tail};
  }
};