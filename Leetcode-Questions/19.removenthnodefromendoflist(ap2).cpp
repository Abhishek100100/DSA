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
    /*
    -  There are two approaches to solve this, let's solve with approach 1
    - Approach 2 : one pass solution
    - In this core logic is to use slow and fast pointer
    - move fast "n" steps ahead and once it reaches that assign head to slow
    - now keep moving both until fast hit's the end and then slow will point to the delnode
    - adjust pointers accordingly

    - The time and space complexity for this approach is O(n) and O(1) respectively, where n is the number of nodes in the linked list.
    */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;
        int target = n;

        // step 1 : move the fast pointer n steps ahead first
        while(target && fast!=nullptr)
        {
            fast = fast->next;
            target--;
        }

        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Don't forget to free the memory of the old head
            return newHead;
        }

        // step 2 : move till the end of the LL
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delnode = slow->next;
        slow->next = delnode->next;
        delete delnode;

        return head;
    }
};