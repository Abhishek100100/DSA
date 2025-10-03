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

Node* deleteHead(Node* head)
{
    Node* temp = head;
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;

}

Node* deleteKthPosition(Node* head, int k)
{
    if(head==NULL) return head; //empty
    if(k==1)                    //single element
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    Node* temp = head;
    Node* prev=NULL;

    while(temp)
    {
        count++;
        if(count==k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev =temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteElement(Node* head, int k)
{
    if(head==NULL) return head; //empty
    if(head->data==k)                    //single element
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp =  head;
    Node* prev = NULL;
    while(temp)
    {
        if(temp->data==k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev =temp;
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int> vecto={2,4,6,8,10};
    Node* head = convertArrToLL(vecto);
    //head = deleteHead(head);
    //head = deleteTail(head);
    //head = deleteKthPosition(head,6);
    head = deleteElement(head,8);
    traverseSLL(head);

}