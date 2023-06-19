// by watercolor, 2022-09-01

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = nullptr, *head;
        ListNode *a = list1, *b = list2;

        if(list1 == nullptr) {
            return list2;
        } else if(list2 == nullptr) {
            return list1;
        }

        while(!(a == nullptr && b == nullptr)) {
            if(a == nullptr || (b != nullptr && a->val > b->val)) {
                swap(a, b);
            } else {
                if(result == nullptr) {
                    head = result = new ListNode(a->val);
                } else {
                    head->next =  new ListNode(a->val);
                    head = head->next;
                }

                a = a->next;
            }
        }

        return result;
    }
};
