#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list
    }
};

Node* convertArrToLL(vector<int> &vecto)
{
    Node* head = new Node(vecto[0]);
    Node* mover = head;
    
    for(int i=1;i<vecto.size();i++)
    {
        Node* temp = new Node(vecto[i]);
        mover->next = temp;
        mover = temp; //mover = mover->next will work too
    }
    return head;
}

int traverseSLL(Node* head)
{
    Node* temp= head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}

Node* insertHead(Node* head, int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    return temp;
}

Node* insertTail(Node* head, int val)
{
    if(head==NULL) return new Node(val);

    Node* temp = new Node(val);
    Node* curr = head;
    
    while(curr->next!=NULL) curr=curr->next;
    curr->next = temp;
    temp->next=NULL;
    return head;

}

Node* insertKthPosition(Node* head, int k, int val) {
    if (k < 1) {
        // Invalid position
        return head;
    }
    
    if (k == 1) {
        // Inserting at the beginning
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    
    Node* curr = head;
    for (int count = 1; curr != NULL && count < k - 1; count++) {
        curr = curr->next;
    }
    
    if (curr == NULL) {
        // k is greater than the number of nodes
        return head;
    }
    
    Node* temp = new Node(val);
    temp->next = curr->next;
    curr->next = temp;
    
    return head;
}


Node* insertBeforeElement(Node* head, int ele, int val) {
    if (head == NULL) return head; // If the list is empty

    // If the element to insert before is the head
    if (head->data == ele) {
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == ele) {
            Node* temp = new Node(val);
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next; // Move to the next node
    }
    // If the element is not found, return the unchanged list
    return head;
}



int main(){
    vector<int> vecto={2,4,6,8,10};
    Node* head = convertArrToLL(vecto);
    //head = insertHead(head,1); 
    //head = insertTail(head,12);
    //head = insertKthPosition(head,6,13);
    head = insertBeforeElement(head,8,7);
    traverseSLL(head);

}