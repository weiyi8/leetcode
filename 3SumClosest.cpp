/* 16. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, mid = 1, right = n - 1;
        int res = 0, dist = INT_MAX;
        while (left < n - 2) {
            while (mid < right) {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    if (sum - target < dist) {
                        dist = sum - target;
                        res = sum;
                    }
                    right--;
                } else {
                    if (target - sum < dist) {
                        dist = target - sum;
                        res = sum;
                    }
                    mid++;
                }
            }
            do {left++;} while (left + 1 < n && nums[left] == nums[left - 1]);
            mid = left + 1;
            right = n - 1;
        }
        return res;
    }
};
