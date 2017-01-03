/* #1
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); ++i) {
            auto p = hash.find(target - nums[i]);
            if ( p != hash.end()) {
                res[0] = i;
                res[1] = p->second;
                return res;
            } else {
                hash[nums[i]] = i;
            }
        }
        return res;
    }
};
