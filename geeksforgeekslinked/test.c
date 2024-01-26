#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

void create_list(node **head, int num) {
    node *current;
    printf("Enter the data of the node 1: ");
    scanf("%d", &((*head)->data));
    (*head)->link = NULL;

    node *temp = *head;

    for (int i = 1; i < num; i++) {
        current = malloc(sizeof(node));
        printf("Enter the data of the node %d: ", i + 1);
        scanf("%d", &(current->data));
        current->link = NULL;
        temp->link = current;
        temp = current;
    }
}

void display(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        printf("The data you entered for node %d is: %d\n", count, head->data);
        head = head->link;
    }
}

node *delete_node(node *head, int num) {
    if (num == 0) {
        node *temp = head;
        head = head->link;
        free(temp);
    } else {
        node *temp = head;
        for (int i = 0; i < num - 1; i++) {
            temp = temp->link;
        }
        node *next = temp->link;
        temp->link = next->link;
        free(next);
    }
    return head;
}

node *find_dup(node *head) {
    node *current = head;
    while (current != NULL) {
        int num = current->data;
        node *temp = current;
        while (temp->link != NULL) {
            if (num == temp->link->data) {
                temp->link = delete_node(temp->link, 0);
            } else {
                temp = temp->link;
            }
        }
        current = current->link;
    }
    return head;
}

int main(void) {
    int num;
    printf("How many nodes are going to be? ");
    scanf("%d", &num);

    node *head = malloc(sizeof(node));
    create_list(&head, num);

    head = find_dup(head);

    printf("Modified linked list:\n");
    display(head);

    return 0;
}

