/*
33. Search in Rotated Sorted Array 

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = 0, b = nums.size() - 1;
        while (a <= b) {
            int c = (b - a) / 2 + a;
            if (nums[c] == target) return c;
            if (nums[a] <= nums[c]) { // rotation does not occur between a and c
                if (nums[a] <= target && target < nums[c]) b = c - 1;
                else a = c + 1;
            } else { // rotation does not occur between c and b
                if (nums[b] >= target && target > nums[c]) a = c + 1;
                else b = c - 1;
            }
        }
        return -1;
    }
};
