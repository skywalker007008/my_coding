// Problem Link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step 1: Find the last rising number sequence
        vector<int>::iterator it = nums.end()-2;
        vector<int>::iterator index = nums.end()-1;
        char temp = 0;
        char old = *index;
        for (; it >= nums.begin(); it--) {
            if (*it<old) {
                old = *it;
                break;
            }
            old = *it;
        }
        
        // If no such sequence, rewrite from the end to start
        if (it < nums.begin()) {            
            for (it = nums.begin(); it < index; it++, index--) {
                temp = *index;
                *index = *it;
                *it = temp;
            }
            return;
        }
        // Find such sequence, then shift *it with the smallest value that is bigger than it.
        // Can use the 
        while (index > it) {
            if (*index > old) {
                *it = *index;
                *(index) = old;
                break;
            }
            index--;
        }
        
        // Reorder the rest after it
        
        for (index = nums.end()-1; index > it;) {
            temp = *index;
            *(index--) = *(++it);
            *it = temp;
        }
    }
};