#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;    //data member
    Node* next;  //pointer to next element
    Node* prev;  //pointer to prev element

    // constructor
    public:
    Node (int data1, Node* next1, Node* prev1)
    {
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided pointer
        prev=prev1;  // Initialize prev with the provided pointer
    }

    Node (int data1)
    {
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list
        prev=nullptr;  //Initilize prev with null 
    }
};

Node* convertArrToDLL(vector<int> &vecto)
{
    Node* head = new Node(vecto[0]);
    Node* prev = head;
    for(int i=1;i<vecto.size();i++)
    {
        Node* temp = new Node(vecto[i],nullptr,prev);
        prev->next = temp;
        prev=temp;
    }
    return head;
}

void traversalDLL(Node* head)
{
    Node* temp= head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHeadDLL(Node* head)
{
    Node* temp = head;
    head=head->next;
    head->prev= nullptr;
    free(temp);
    return head;
}

Node* deleteTailDLL(Node* head)
{
    Node* prev = head;

    while(temp->next!=NULL)
    {
        temp=temp->next
    }


}

int main()
{
    vector<int> vecto = {1,2,3,4,5,6};
    Node* head= convertArrToDLL(vecto);
    head = deleteHeadDLL(head);
    traversalDLL(head);
    return 0;
}