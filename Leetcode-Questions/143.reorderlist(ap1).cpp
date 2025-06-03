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
    // There exists multiple ways to solve it.
    /*
    Approach 1 : 
    a) Finding middle node with slow-fast pointers
    b) We will reverse the right half of the LL
    c) We will adjust pointers within a while loop 
    */

    // Time and Space complexity(considering auxiliary space for recursion):
    // O(n) and O(n) respectively, where n is the number of nodes in the linked list.
    

public:
    ListNode* reverseLL(ListNode* node)
    {
        // recursive solution to reverse a linked list
        if(node==NULL || node->next==NULL) return node;

        ListNode* newhead = reverseLL(node->next);
        ListNode* front = node->next;
        front->next = node;
        node->next = NULL;
        return newhead;
    }

    void reorderList(ListNode* head) {
        // step 1 :  find the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2: reverse the linked list from middle node
        // reverse node stores the head of reversed LL
      ListNode* reverse = reverseLL(slow);
      ListNode* current = head;
      
      // step 3 : adjust the pointers
      // we will keep on moving with this rev pointer to reach the end of reversed LL
      // make a diagram everything will be clear
      while(reverse->next!=NULL)
      {
        ListNode* tempprevious = reverse->next;
        ListNode* temp = current->next;
        current->next = reverse;
        reverse->next = temp;
        current = temp;
        reverse = tempprevious;
      }

    }
};