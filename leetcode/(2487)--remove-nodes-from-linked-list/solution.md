# 2487: remove-nodes-from-linked-list

[Problem on Leetcode](https://leetcode.com/problems/remove-nodes-from-linked-list/)

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use recursive method to get the required list after element i. And combine i or not  as the return value.

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: $O(n)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(1)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = reform(head);
        return node->next;
    }

    ListNode* reform(ListNode* head) {
        // cout << "Reform Start" << endl;
        // print(head);
        if (head->next == nullptr) {
            // The lastone, return itself
            // ListNode node = (ListNode){head->val, head};
            // cout << ((&node)->next) << endl;
            // print((&node)->next);
            // return &node;
            ListNode* node = (ListNode*)malloc(sizeof(ListNode));
            node->val = head->val;
            node->next = head;
            return node;
        } else {
            ListNode* node = reform(head->next);
            if (head->val >= node->val) {
                // This node is not smaller than the following list, add this node to the front of the list
                // cout << "HIT HERE" << endl;
                head->next = node->next;
                node->val = head->val;
                node->next = head;
            }
            // Else, just return the node
            // cout << "Reform Over" << endl;
            // cout << (node->next) << endl;
            // print(node->next);
            return node;
        }
    }

    void print(ListNode* head) {
        ListNode* now = head;
        while (now != nullptr) {
            cout << now->val << "-";
            now = now->next;
        }
        cout << "" << endl;
    }
};
```