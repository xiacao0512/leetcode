// by watercolor, 2022-11-15

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1, *t2 = l2, *prev, dummy = ListNode();
        int s1 = sizeofListNode(t1), s2 = sizeofListNode(t2);

        if(s1 - s2 < 0) {
            std::swap(t1, t2);
        }
        dummy.next = t1;
        prev = &dummy;

        int carry = 0;
        while(t1 != nullptr || (t2 != nullptr && carry != 0)) {
            int sum = t1->val + carry;
            
            sum += (t2 == nullptr) ? 0 : t2->val;
            t1->val = sum % 10;
            carry = sum / 10;

            t1 = t1->next;
            t2 = (t2 == nullptr) ? t2 : t2->next;
            prev = prev->next;
        }

        if(prev->next == nullptr && carry != 0) {
            prev->next = new ListNode(carry);
        }

        return dummy.next;
    }

private:
    int sizeofListNode(const ListNode *l)
    {
        int size=0;

        while(l != nullptr) {
            l = l->next;
            size++;
        }

        return size;
    }
};
