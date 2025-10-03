/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* current = head;
        Node* previous= NULL;
        
        while (current != nullptr)
        {
            // Swap next and prev pointers
            previous = current->prev;
            current->prev = current->next;
            current->next = previous;

            // Move to the next node in the original list
            current = current->prev;
        }

        // previous is now the new head of the reversed list
        if (previous != nullptr)
            head = previous->prev;

        return head;
    }
};
