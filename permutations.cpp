/*
46. Permutations   

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        //using backtracking, swapping current pos with following positions
        dfs(nums, 0, n, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int len, int n, vector<vector<int>>& res) {
        if (len == n) {
            res.push_back(nums);
            return;
        }
        for (int i = len; i < n; ++i) {
             swap(nums[len], nums[i]);
             dfs(nums, len + 1, n, res);
             swap(nums[len], nums[i]);
        }
    }
};
