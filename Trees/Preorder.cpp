#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node()
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data)
    {
        data = data;
        left = new Node(left);
        right = new Node(right);
    }
}

int main()
[
    //node bana 
    //tree me inputs lele
    //preorder ka logic likh
    //print ka logic likh
    return 0;
]