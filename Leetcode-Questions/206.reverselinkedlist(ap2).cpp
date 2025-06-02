// Leetcode 206: Reverse Linked List
// Approach 2 : Iterative Optimal Solution
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
        // Iterative solution

        // Think of it in terms of front, previous and temp and then adjust pointers
        // Solve for smaller problem first, then expand for larger ones.
        
        // if single node is present
        if(head==NULL) return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};