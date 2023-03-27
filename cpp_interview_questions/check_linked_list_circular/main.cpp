#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

int isCircular (struct Node* head) {
    /* If linked list is empty it is circular */
    if (head == NULL) {
        return 1;
    }
    struct Node * ptr;
    ptr = head->next;

    /* Traversing linked list till last node */
    while (ptr != NULL && ptr != head) {
        ptr = ptr->next;
    }

    /* Condition for circular linked list */
    return (ptr == head);
}

struct Node * new_node(int data) {
    struct Node * temp;
    temp = (struct Node*) malloc (sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node * head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    if(isCircular(head)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    head->next->next->next->next = head;
    if (isCircular(head))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}