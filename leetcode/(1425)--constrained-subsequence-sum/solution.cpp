// Link: https://leetcode.com/problems/constrained-subsequence-sum/description/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int size = nums.size();
        // Only One
        if (size == 0) {
            return nums[0];
        }
        bool sign = true;
        vector<int> gaps;
        // gaps.push_back(0);
        // Find the first and last positive number
        // Save the numbers of same symbol
        int i;
        sign = (nums[0] >= 0);
        
        for (i = 1; i < size; i++) {
            if (sign != (nums[i] >= 0)) {
                gaps.push_back(i);
                sign = !sign;
            }
        }
        gaps.push_back(size);
        printVector(gaps);
        if (gaps.size() == 1) {
            // All pos or all neg
            if (sign) {
                return maxInRange(nums, 0, size-1, k);
            } else {
                return maxVector(nums);
            }
        }
        int max = 0;
        int sum = -1;
        if (nums[0] < 0) {
            sum = maxInRange(nums, gaps[0], gaps[1]-1, k);
            i = 1;
        } else {
            sum = maxInRange(nums, 0, gaps[0]-1, k);
            i = 0;
        }
        max = sum;
        for (; i < gaps.size() - 2;) {
            int v = maxInRange(nums, gaps[i], gaps[i+1]-1, k);
            int pos = maxInRange(nums, gaps[i+1], gaps[i+2]-1, k);
            int tmp = v+pos;
            if (tmp >= 0) {
                if (v+max < 0) {
                    max = pos;
                    sum = pos;
                } else {
                    sum += tmp;
                    if (sum > max) {
                        max = sum;
                    }
                }
            } else {
                if (pos > max) {
                    max = pos;
                    sum = pos;
                } else {
                    sum += tmp;
                }
                    
            }
            i += 2;
        }
        return max;

    }

    int maxVector(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }

    int printVector(vector<int>& vec) {
        cout << "VECTOR:";
        for (int i: vec) {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }

    int maxInRange(vector<int>& nums, int start, int end, int k) {
        int v = 0;
        if (nums[start] >= 0) {
            for (int i = start; i <= end; i++) {
                v += nums[i];
            }
            return v;
        }

        if (k == 1) {
            for (int i = start; i <= end; i++) {
                v += nums[i];
            }
            return v;
        }

        // Negative
        if (k >= end-start+2) {
            return 0;
        }
        int* dp = (int*)malloc(k*sizeof(int));
        memset(dp, 0, k*sizeof(int));
        int p = 0;
        // Initialize to make sure dp[i] >= dp[i+1]
        dp[k-1] = nums[start+k-1];
        for (int i = k-2; i >= 0; i--) {
            p = nums[start+i];
            dp[i] = p < dp[i+1] ? dp[i+1] : p;
        }
        // print_dp(dp, k);
        start += k;
        while (start <= end) {
            // Update the value
            // Put the max of these k values at 0.
            for (int i = 0; i < k && start+i <= end; i++) {
                p = dp[0] > dp[i] ? dp[0] : dp[i];
                p = p + nums[start+i];
                dp[i] = p;
                // printf("dp[%d]=%d, dp[0]=%d\n", i, p, dp[0]);
                dp[0] = dp[0] < p ? p : dp[0];
                // printf("dp[%d]=%d, dp[0]=%d\n", i, p, dp[0]);
            }
            // Reorder so that dp[i] >= dp[i+1]
            // cout << "Before Reorder  ";
            // print_dp(dp, k);
            for (int i = k-2; i >= 0; i--) {
                // printf("dp[%d]=%d, dp[%d]=%d\n", i, dp[i], i+1, dp[i+1]);
                dp[i] = dp[i] < dp[i+1] ? dp[i+1] : dp[i];
                // printf("dp[%d]=%d, dp[%d]=%d\n", i, dp[i], i+1, dp[i+1]);
            }
            cout << "After Reorder  ";
            start += k;
            // print_dp(dp, k);
        }
        // Return dp[0];
        int i = dp[0];
        free(dp);
        return i;
    }
    
    void print_dp(int* dp, int k) {
        cout << "NOW DP: ";
        for(int i = 0; i < k; i++) {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
};