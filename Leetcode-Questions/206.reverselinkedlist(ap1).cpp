// Leetcode 206: Reverse Linked List
// Approach 1 : Recursive Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // One solution could be to push all elements to stacks and then fill the data
        // Two optimal approaches - iterative and recursive
        // Recursive solution

        // Think of it in terms of front, newhead and head and then adjust pointers
        // Solve for smaller problem first, then expand for larger ones.
        // we must write a base case

        // it means either it's empty list or has just a single element
        if(head==NULL || head->next==NULL) return head;

        // declaring new head, it's like solving for n-1 length LL
        // draw diagrams it will be clear
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next=NULL;
        return newhead;
    }
};