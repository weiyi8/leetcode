/*
32. Longest Valid Parentheses   

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/



class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        int maxLen = 0;
        stack<int> pos;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                pos.push(i + 1);
            } else {
                if (!pos.empty() && pos.top() > 0) {
                    pos.pop();
                } else {
                    pos.push(-(i+1));
                }
                
            }
        }
        int pre = s.size() + 1;
        while (!pos.empty()) {
            int cur = pos.top();
            pos.pop();
            len = abs(pre) - abs(cur) - 1;
            maxLen = max(maxLen, len);
            pre = cur;
        }
        maxLen = max(maxLen, abs(pre) - 1);
        return maxLen;
    }
};
