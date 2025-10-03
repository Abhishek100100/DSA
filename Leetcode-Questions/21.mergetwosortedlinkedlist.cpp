// LeetCode problem number: 21
// LeetCode problem name: Merge Two Sorted Lists
// LeetCode problem link: https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // using the dummy node and temp node approach
        // we are storing the dummy node and pointing it to the head of new list
        ListNode* dummy = new ListNode(-1, NULL) ;
        ListNode* temp = dummy;

        // Pointers to iterate the two list
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL && temp2 != NULL)
        {
            
            if(temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }

            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if(temp1 == NULL) temp->next = temp2;
        if(temp2 == NULL) temp->next = temp1;

        return dummy->next;
    }
};