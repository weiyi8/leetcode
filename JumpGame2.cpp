/*
45. Jump Game II   
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<int> nodes;
        nodes.push(0);
        nodes.push(-1);
        int res = 0;
        int range = 0;
        while (!nodes.empty()) {
            if (nodes.front() == -1) {
                nodes.pop();
                nodes.push(-1);
                res++;
            } else {
                int pos = nodes.front();
                nodes.pop();
                if (pos == n - 1) {
                    return res;
                }
                for (int i = range + 1 - pos; i <= nums[pos] && pos + i < n; ++i) {
                    nodes.push(pos + i);
                    range = pos + i;
                }
            }
        }
        return res;
    }
};
