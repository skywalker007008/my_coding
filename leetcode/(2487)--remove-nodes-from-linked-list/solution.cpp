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