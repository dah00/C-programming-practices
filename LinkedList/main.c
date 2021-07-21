#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
} Node;

void print_list(Node *head);
void append(Node *head, int val);
void push(Node **head, int val);
int removeFirst(Node **head);
int removeLast(Node *head);
int remove_by_index(Node **head, int n);
int remove_by_value(Node **head, int val);

int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));

    head->val = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->val = 2;
    head->next->next = NULL;

    print_list(head);

    append(head, 3);
    append(head, 4);
    append(head, 5);

    print_list(head);

    push(&head, 0);

    print_list(head);

    removeFirst(&head);

    print_list(head);

    removeLast(head);

    print_list(head);

    //remove_by_index(&head, 3);

    printf("%d \n", remove_by_index(&head, 2));

    print_list(head);

    return 0;
}

void print_list(Node *head){
    Node *current = head;

    while(current != NULL){
        printf("%d\ ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Adding item at the end of the list
void append(Node *head, int val){
    Node *current = head;

    while(current->next != NULL){
        current = current->next;
    }
    // Now we can add a new value;
    current->next = (Node*)malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;
}

// Adding item at the beginning of the list
void push(Node **head, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

// Removing the first item
int removeFirst(Node **head){
    int value = -1;
    Node *secondNode = NULL;

    if(*head == NULL)
        return -1;

    secondNode = (*head)->next;
    value = (*head)->val;
    free(*head);
    *head = secondNode;

    return value;
}

// Removing the last item
int removeLast(Node *head){
    int value = 0;

    // if there is only one item in the list
    if(head->next == NULL){
        value = head->val;
        free(head);
        return value;
    }

    // if there two or more items in the list
    Node *current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    value = current->next->val;
    free(current->next);
    current->next = NULL;
    return value;
}


int remove_by_index(Node **head, int n){
    Node *current = *head;
    if(current == NULL){
        return -1;
    }

    // if n = 0;
    int value = 0;
    if(n==0){
        removeFirst(head);
    }

    for(int i=0; i<n-1; i++){
        if(current->next == NULL){
            return -1;
        }
        current = current->next;
    }
    Node *tempNode = current->next;
    value = tempNode->val;
    current->next = tempNode->next;
    free(tempNode);
    return value;

}

int remove_by_value(Node **head, int val){
    Node *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return removeFirst(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}
