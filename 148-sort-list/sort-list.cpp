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
    using node = ListNode;

    node* findMiddle(node* head) {
        node* slow = head;
        node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    node* merge(node* l1, node* l2) {
        node dummy(0);
        node* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        node* mid = findMiddle(head);
        node* left = head;
        node* right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};