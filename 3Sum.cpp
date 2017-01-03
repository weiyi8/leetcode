/* #15
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        // two pointers
        int left = 0, mid = 1, right = n - 1;
        while (left < n - 2) {
            while (mid < right) {
                if (nums[left] + nums[mid] + nums[right] == 0) {
                    vector<int> r({nums[left], nums[mid], nums[right]});
                    res.push_back(r);
                    do {mid++;} while (mid + 1 < n && nums[mid] == nums[mid - 1]);
                    right = n - 1;
                } else if (nums[left] + nums[mid] + nums[right] > 0) {
                    right--;
                } else {
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
