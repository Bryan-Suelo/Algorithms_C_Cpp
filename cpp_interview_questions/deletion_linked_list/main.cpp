#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

void push(Node ** head_ref, int new_data) {
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(Node ** head_ref, int key) {
    /* Store head node */
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        /* Change head */
        *head_ref = temp->next;
        /* Free old head */
        delete temp;
        return;
    }
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        /* Key was not present in linked list */
        if (temp == NULL) {
            return;
        }
        /* Unlink the node from linked list */
        prev->next = temp->next;
        delete temp;
    }
}

void printList(Node * node) {
    while(node != NULL) {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printList(head);

    deleteNode(&head, 1);
    printList(head);
}
