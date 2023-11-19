// Problem Link: https://leetcode.com/problems/sort-list/description//

// Issue: Face O(n^2) problems

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

 // -1 5 3 4 0
 /*
  * -1,5,3,4,0   -1,3,5,4,0   -1,3,4,5,0     -1,3,4,0,5
  * -1,3,4,0,5   -1,3,4,0,5   -1,3,0,4,5     -1,3,0,4,5

  */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // a-->b-->c, swap (ab) if needed, and swap (bc/ac) if needed
        ListNode *temp = NULL;
        ListNode *now = head;
        // Nothing
        if (head == NULL) {
            return head;
        }
        ListNode *next = head->next;
        bool cond = true;
        // Only one
        if (next == NULL) {
            return head;
        }

        while (cond) {
            temp = NULL;
            now = head;
            next = head->next;
            cond = false;
            while (next != NULL) {
                // Need switch
                if (now -> val > next-> val) {
                    cond = true;
                    swap(temp, now, next);
                    if (head == now) {
                        head = next;
                    }
                    // Redefine the values
                    temp = next;
                    // now = now;
                    next = now->next;
                }
                // No swap, just go ahead
                else {
                    temp = now;
                    now = next;
                    next = next->next;
                }
            }
        }
        return head;
    }

    // Swap the info of listnode a and b
    void swap(ListNode* temp, ListNode* a, ListNode* b) {
        if (temp != NULL) {
            temp->next = b;
        }
        a->next = b->next;
        b->next = a;
    }

};