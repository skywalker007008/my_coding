// Link: https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* former = nullptr;
        ListNode* now = head;
        ListNode* firstEnd = nullptr;
        int i = 1;
        // Step 1: Follow to the right start now
        while (i < left) {
            firstEnd = now;
            now = now->next;
            i++;
        }

        // Step 2: Reverse several points
        while (i++ <= right) {
            ListNode* next = now->next;
            // Set the now
            now->next = former;
            former = now;
            now = next;
        }
        // Step 3: Link the others

        // Link the others
        
        if (left == 1) {
            head->next = now;
            return former;
        } else {
            firstEnd->next->next = now;
            firstEnd->next = former;
            return head;
        }
        
    }
};