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

bool searchSLL(Node* head, int num)
{
    Node* temp= head;
    while(temp)
    {
        if(temp->data==num) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> vecto={2,6,4,8,10};
    Node* head = convertArrToLL(vecto);
    cout << "Element present " << searchSLL(head,16);
}