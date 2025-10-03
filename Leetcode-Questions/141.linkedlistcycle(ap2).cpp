// Leetcode 141: Linked List Cycle
// Approach 2 : using tortoise and hare algorithm
// Link : https://leetcode.com/problems/linked-list-cycle/description/
// Time and space complexity: O(n) and O(1) respectively
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
    // There are two approches to solve this
    // Approach 1 : do hashing of node and then, if two similar nodes are found return false
    // Approach 2 : tortoise and hare algorithm, i.e slow and fast pointer
    
    // Approach 2 Solution (optimised space complexity)
    bool hasCycle(ListNode *head) {
        //Let's make two pointers
        ListNode* tortoise=head;
        ListNode* hare = head;

        // this condition is because hare will reach the end faster as it jumps two position
        while(hare!=NULL && hare->next!=NULL)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            // at no point in a linear LL, the hare and tortoise will be equal
            if(tortoise==hare) return true;
        }
        return false;
    }
};