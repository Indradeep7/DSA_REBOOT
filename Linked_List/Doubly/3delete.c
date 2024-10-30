#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} *node;

node head = NULL, temp;

void create_node(int data) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) temp = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void delete_beg() {
    if (head == NULL) return;

    node to_delete = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(to_delete);
}

void delete_end() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
}

void delete_index(int pos) {
    if (head == NULL || pos < 1) return;

    if (pos == 1) {
        delete_beg();
        return;
    }

    node temp = head;
    int x = 1;

    while (temp->next != NULL && x < pos) {
        temp = temp->next;
        x++;
    }

    if (temp->next == NULL && x < pos) return;

    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void print_node() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int sno = 65;
    temp = head;
    while (temp != NULL) {
        printf("%c. data = %d\t", sno, temp->data);
        temp = temp->next;
        sno++;
    }
    printf("\n");
}

int main() {
    printf("\n\nInitial creation of nodes:\n");
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    printf("\n\nDelete node at position 2:\n");
    delete_index(2);
    print_node();

    printf("\n\nDelete the first node:\n");
    delete_beg();
    print_node();

    printf("\n\nDelete the last node:\n");
    delete_end();
    print_node();

    return 0;
}
