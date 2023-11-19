#include <map>

typedef struct link {
    int index;
    link* next;
}my_link;

// typedef struct MyHash {
//     // noexcept is recommended, but not required
//     std::size_t operator()(const int& s) const /*noexcept*/
//     {
//         const int div = 200000001;
//         return s % div;
//     }
// }MyHash;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Store the index of a same value
        unordered_map<int, pair<my_link*, my_link*>> same_map;
        // Store shown index
        unordered_set<int> shown_set;
        // bfs queue
        deque<int> queue;
        // Steps
        int step = 0;
        int index=0;

        int size = arr.size();
        if (size == 1) {
            return 0;
        }
        // Store the same elements
        for (int i = 0; i < size; i++) {
            int value = arr[i];
            my_link* l = create_link(i);
            if (same_map.find(value) == same_map.end()) {
                same_map[value] = pair<my_link*, my_link*>(l,l);
            } else {
                same_map[value].second->next = l;
                same_map[value].second = l;
            }
        }
        // Delete element only single time
        for (auto it = same_map.begin(); it != same_map.end();) {
            if (it->second.first->next == NULL) {
                free(it->second.first);
                same_map.erase(it);
                it = same_map.begin();
            } else {
                it++;
            }
        }
        // Start finding
        queue.push_back(size-1);
        queue.push_back(-1);
        shown_set.insert(size-1);

        int t;
        bool cond = true;

        while (cond) {
            while(true) {
                std::deque<int>::iterator it = queue.begin();
                index = *it;
                // Break Condition
                if (index == -1) {
                    queue.pop_front();
                    break;
                }
                t = index+1;
                // Case 1:
                if (t < size && shown_set.find(t) == shown_set.end()) {
                    queue.push_back(t);
                    shown_set.insert(t);
                }
                t = index-1;
                // Case 2:
                if (t == 0) {
                    cond = false;
                    break;
                }
                if (t > 0 && shown_set.find(t) == shown_set.end()) {
                    queue.push_back(t);
                    shown_set.insert(t);
                }
                // Case 3:
                if (same_map.find(arr[index]) != same_map.end()) {
                    // For each element with same number, add to the stack
                    for (my_link* it2 = same_map[arr[index]].first; it2 != NULL; it2 = it2->next) {
                        if (it2->index == index) {
                            continue;
                        }
                        if (it2->index == 0) {
                            cond = 0;
                            queue[1] = -1;
                            break;
                        }
                        queue.push_back(it2->index);
                        shown_set.insert(it2->index);
                    }
                    free_links(same_map[arr[index]].first);
                    same_map.erase(arr[index]);
                }
                queue.pop_front();

            }
            step++;
            // Erase all in same_map(To be decided)
            queue.push_back(-1);
            cout << endl;
        }

        // Erase
         // Delete element only single time
        for (auto it = same_map.begin(); it != same_map.end();it++) {
            free_links(it->second.first);
        }
        return step;

    }

    void free_links(my_link* head) {
        my_link* now = head;
        my_link* next;
        while (now != NULL) {
            next = (now)->next;
            free(now);
            now = next;
        }
    }

    my_link* create_link(int index) {
        my_link* l = (my_link*)malloc(sizeof(my_link));
        l->index = index;
        l->next = NULL;
        return l;
    }
};

// Link: https://leetcode.com/problems/jump-game-iv/description/

// Improvement: Use vector instead of linkedlist to save space