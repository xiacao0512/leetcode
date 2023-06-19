// by watercolor, 2022/09/10

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count=0;
        ListNode *tail1=head, *tail2=head;

        if(head->next == nullptr) {
            return nullptr;
        }

        while(tail1->next->next != nullptr) {
            tail1 = tail1->next;
            count++;

            if(count >= n) {
                tail2 = tail2->next;
            }
        }

        if(n == count+2) {
            return tail2->next;
        } else {
            tail2->next = tail2->next->next;
            return head;
        }
    }
};
