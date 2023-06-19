// by watercolor, 2022-11-12

class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *tail = head, *prev = nullptr;
        while(tail != nullptr && tail->next != nullptr) {
            ListNode *temp = tail->next;
            tail->next = tail->next->next;
            temp->next = tail;

            if(prev != nullptr) {
                prev->next = temp;
            }

            if(temp->next == head) {
                head = temp;
            }

            prev = tail;
            tail = tail->next;
        }

        return head;
    }
};
