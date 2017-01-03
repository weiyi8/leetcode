/* 18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        
        // two pointers, similar to 2sum and 3sum
        int p0 = 0, p1 = 1, p2 = 2, p3 = n - 1;
        while (p0 < n - 3) {
            while (p1 < n - 2) {
                while (p2 < p3) {
                    if (nums[p0] + nums[p1] + nums[p2] + nums[p3] == target) {
                        vector<int> r({nums[p0], nums[p1], nums[p2], nums[p3]});
                        res.push_back(r);
                        do { p2++; } while (p2 + 1 < n && nums[p2] == nums[p2 - 1]);
                        p3 = n - 1;
                    } else if (nums[p0] + nums[p1] + nums[p2] + nums[p3] > target) {
                        p3--;
                    } else {
                        p2++;
                    }
                }
                do { p1++; } while (p1 + 1 < n && nums[p1] == nums[p1 - 1]);
                p2 = p1 + 1;
                p3 = n - 1;
            }
            do { p0++; } while (p0 + 1 < n && nums[p0] == nums[p0 - 1]);
            p1 = p0 + 1;
            p2 = p1 + 1;
            p3 = n - 1;
        }
        return res;
    }
};
