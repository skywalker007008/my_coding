// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Step 1: Find the place where the rotation happens.
        // Use binary search
        uint16_t end = nums.size()-1;
        
        if (nums[0] <= nums[end]) {
            // // All way rising
            if (target < nums[0] || target > nums[end]) {
                return -1;
            }
            return findTarget(nums, 0, end, target);
        }
        
       
            uint16_t pl = findIndexRotation(nums, 0, end);
            // Step 2: According to target, judge which possibly has the value target
            if (target == nums[end]) {
                return end;
            }
            if (target == nums[0]) {
                return 0;
            }
            if (target == nums[pl]) {
                return pl;
            }
            if (target == nums[pl-1]) {
                return pl-1;
            }

            if (target < nums[end] && target > nums[pl]) {
                return findTarget(nums, pl, end, target);
            } else if (target > nums[0] && target < nums[pl-1]) {
                return findTarget(nums, 0, pl-1, target);
            } else {
                // Out of range
                return -1;
            }
        
        return -1;
    }

    uint16_t findIndexRotation(vector<int>& nums, uint16_t start, uint16_t end) {
        if (end-start <= 1) {
            if (nums[end] < nums[start]) {
                return end;
            } else {
                cout << "Bad Case" << endl;
            }
        }
        uint16_t index = (start + end)/2;
        // Check index
        int value = nums[index];
        if (value < nums[index-1]) {
            // Hit the place
            return index;
        }
        if (nums[index+1] < value) {
            return (index+1);
        }
        // Judge according to the end, to find which side it happens.
        if (value < nums[start]) {
            return findIndexRotation(nums, start, index);
        } else if (value > nums[end]) {
            return findIndexRotation(nums, index, end);
        } else {
            // Invalid Possibility
            cout << "Hit Invalid" << endl;
            return -1;
        }
    }

    int findTarget(vector<int>& nums, uint16_t start, uint16_t end, int target) {
        if (start >= end) {
            if (nums[start] == target) {
                return start;
            } else {
                return -1;
            }
        }
        uint16_t pl = (start+end)/2;
        if (nums[pl] == target) {
            return pl;
        }
        if (nums[pl] < target) {
            return findTarget(nums, pl+1, end, target);
        } else {
            return findTarget(nums, start, pl-1, target);
        }
    }
};