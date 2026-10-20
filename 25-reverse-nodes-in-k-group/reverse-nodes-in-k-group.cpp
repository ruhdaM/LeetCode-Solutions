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

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        node* temp = head;

        for (int i = 0; i < k; i++) {

            if (temp == nullptr) // matlab ki k > length of node
                return head;

            temp = temp->next;
        }

        node* prev = nullptr;
        node* curr = head;

        for (int i = 0; i < k; i++) {
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};