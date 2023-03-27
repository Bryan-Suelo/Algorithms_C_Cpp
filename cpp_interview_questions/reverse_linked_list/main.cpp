#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

static void reverse (struct Node ** head_ref) {
    struct Node * prev = NULL;
    struct Node * curr = *head_ref;
    struct Node * next = NULL;

    while (curr != NULL) {
        /* Store next*/
        next = curr->next;

        /* Reverse current node's ponter */
        curr->next = prev;

        /* Move pointers one position ahead */
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

void push(struct Node ** head_ref, int new_data) {
    struct Node * new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void printList(struct Node* head) {
    struct Node * temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    printList(head);

    reverse(&head);
    printList(head);
}