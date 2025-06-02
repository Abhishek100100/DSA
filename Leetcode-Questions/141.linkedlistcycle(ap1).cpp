// Leetcode 141: Linked List Cycle
// Approach 1 : using hashing
// time and space complexity: O(n) and O(n) respectively
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
    // There are two appraoches to solve this
    // Approach 1 : do hashing of node and then, if two similar nodes are found return false
    // Approach 2 : tortoise and hare algorithm, i.e slow and fast pointer
    
    // Approach 1 Solution (has higher space complexity)
    bool hasCycle(ListNode *head) {
        // remember we are storing the entire node as key in the map.
        unordered_map<ListNode* , int> mp;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            mp[temp]++;
            if(mp[temp]>1) return true;
            else temp=temp->next; 
        }
        return false;
    }
};