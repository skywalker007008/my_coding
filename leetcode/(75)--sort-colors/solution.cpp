
// Link: https://leetcode.com/problems/sort-colors/description/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        uint16_t num[3] = {0,0,0};
        int i = 0;
        // Count the number of each values
        while(i < nums.size()) {
            num[nums[i++]]++;
        }

        // Override
        i = 0;
        for (int j = 0; j < num[0]; j++) {
            nums[i++] = 0;
        }
        for (int j = 0; j < num[1]; j++) {
            nums[i++] = 1;
        }
        for (int j = 0; j < num[2]; j++) {
            nums[i++] = 2;
        }
    }
};