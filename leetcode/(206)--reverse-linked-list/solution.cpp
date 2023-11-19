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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* former = nullptr;

        while (head != nullptr) {
            ListNode* next = head->next;
            // Set the now
            head->next = former;
            former = head;
            head = next;
        }
        return former;
    }
};

// Link: https://leetcode.com/problems/reverse-linked-list/