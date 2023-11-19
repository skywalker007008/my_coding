# 203: remove-linked-list-elements

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
[Problem](https://leetcode.com/problems/remove-linked-list-elements/)

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: $O(n)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(1)$

<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```c++
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* last = head;
        ListNode* newHead = nullptr;
        while (last != nullptr) {
            if (last->val != val) {
                newHead = last;
                break;
            } else {
                last = last-> next;
            }
        }
        if (last == nullptr) {
            return nullptr;
        }
        ListNode* now = last->next;
        while (now != nullptr) {
            if (now->val == val) {
                last->next = now->next;
            } else {
                last = now;
            }
            now = now->next;
        }
        return newHead;
    }
};
```