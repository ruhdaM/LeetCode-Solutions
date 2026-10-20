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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        node* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());

        node dummy(0);
        node* curr = &dummy;

        for (int x : v) {
            curr->next = new node(x);
            curr = curr->next;
        }

        return dummy.next;
    }
};