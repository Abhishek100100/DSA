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
    - Approach 1 : two pass solution
    - The time and space complexity for this approach is O(n) and O(1) respectively, where n is the number of nodes in the linked list.
    */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

       // Step 1 :  find the length of linked list
       ListNode* temp = head;
       int size = 0;
       while(temp)
       {
         size++;
         temp=temp->next;
       }

       //step 2 : find the index of element from start to be deleted
       int ind = size - n ;

       if(ind==0) return head->next; // I can add the node deletion condition, but avoided it for simplicity
       
       // step 3 : move to a node previous to it and then adjust the pointers
       ListNode* prev = head;
       for(int i=0;i<ind-1;i++)
       {
            prev = prev->next;
       }
        
        ListNode* delNode = prev->next;
        prev->next = delNode->next;
        delete(delNode);
        
        return head;
    }
};