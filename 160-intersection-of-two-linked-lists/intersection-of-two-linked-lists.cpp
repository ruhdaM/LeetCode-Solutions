/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;

        for (ListNode* a = headA; a; a = a->next) {
            lenA++;
        }

        for (ListNode* b = headB; b; b = b->next) {
            lenB++;
        }

        if (lenA < lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }

        for (int diff = lenA - lenB; diff > 0; diff--) {
            headA = headA->next;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};