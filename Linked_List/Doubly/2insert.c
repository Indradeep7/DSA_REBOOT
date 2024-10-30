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

void insert_beg(int data) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_end(int data) {
    create_node(data);
}

void insert_index(int data, int pos) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insert_beg(data);
        return;
    }

    node temp = head;
    int current_pos = 1;
    while (temp->next != NULL && current_pos < pos - 1) {
        temp = temp->next;
        current_pos++;
    }

    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next = new_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void print_node() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int index = 1;
    temp = head;
    while (temp != NULL) {
        printf("%d. data = %d\t", index, temp->data);
        temp = temp->next;
        index++;
    }
    printf("\n");
}

int main() {
    printf("\n\nInitial creation of nodes:\n");
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    printf("\n\nInsert 18 at the beginning:\n");
    insert_beg(18);
    print_node();

    printf("\n\nInsert 45 at position 4:\n");
    insert_index(45, 4);
    print_node();

    printf("\n\nInsert 30 at the end:\n");
    insert_end(30);
    print_node();

    return 0;
}
