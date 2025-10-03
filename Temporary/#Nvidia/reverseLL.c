#include <stdio.h>
#include <stdlib.h>

// Standard structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list in-place
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store the next node before we change anything
        next = current->next;

        // Reverse the 'next' pointer of the current node
        current->next = prev;

        // Move pointers one position ahead for the next iteration
        prev = current;
        current = next;
    }

    // After the loop, 'prev' will be the new head of the reversed list
    *head_ref = prev;
}

// Helper function to add a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Helper function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the reversal
int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}
