/*
81. Search in Rotated Sorted Array II  

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/




class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int a = 0, b = nums.size() - 1;
        while (a <= b) {
            int c = (b - a) / 2 + a;
            if (nums[c] == target) return true;
            if (nums[a] < nums[c]) {
                if (nums[c] > target && target >= nums[a]) {
                    b = c - 1;
                } else {
                    a = c + 1;
                }
            } else if (nums[a] > nums[c]) {
                if (nums[b] >= target && target > nums[c]) {
                    a = c + 1;
                } else {
                    b = c - 1;
                }
            } else {
                a++;
            }
        }
        return false;
    }
};
