/* 25. Reverse Nodes in k-Group 

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        while (p) {
            int n = 1;
            ListNode* subhead = new ListNode(0);
            ListNode* tail = p;
            ListNode* post;
            while (p && n <= k) {
                post = p->next;
                pre->next = p->next;
                p->next = subhead->next;
                subhead->next = p;
                p = post;
                n++;
            }
            if (n > k) {
                pre->next = subhead->next;
                tail->next = p;
                pre = tail;
            } else {
                //reserve subhead;
                ListNode* dummy2 = new ListNode(0);
                ListNode* cur = subhead->next;
                ListNode* curpost;
                while (cur) {
                    curpost = cur->next;
                    subhead->next = curpost;
                    cur->next = dummy2->next;
                    dummy2->next = cur;
                    cur = curpost;
                }
                
                pre->next = dummy2->next;
                break;
            }
        }
        return dummy->next;
    }
};
