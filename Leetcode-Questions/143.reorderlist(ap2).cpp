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
    // With approach 1 we were using auxiliary space of recursion stack
    // we can create our own stack and access it
    /*
    Approach 2 : 
    a) We will push the elements into stack and then pop it till n/2 size
    b) iterate over the list and adjust pointers
    */

    // Time and Space complexity for this approach with stack:
    // O(n) and O(n) respectively, where n is the number of nodes in the linked list.
    // Note: This approach is not optimal in terms of space, but it is a valid solution.
    // compared to the first approach, this one uses an explicit stack instead of recursion.
    

public:

    void reorderList(ListNode* head) {
        // step 1 :  store the node in stack
        stack<ListNode*> st;
        ListNode* temp = head;
        ListNode* curr = head;

        while(temp)
        {
            st.push(temp);
            temp = temp->next;
        }

        int llsize = st.size();
        int k = llsize/2;

        // step 2 : 
        while(k)
        {
            temp = curr->next;
            ListNode* topnode = st.top();
            st.pop();
            curr->next = topnode;
            topnode->next = temp;
            curr = temp;
            k--;
        }
        curr->next = NULL;
    }
};