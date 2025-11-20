#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert(int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->prev = NULL;
    t->next = head;
    if (head != NULL)
        head->prev = t;
    head = t;
}

int size() {
    int c = 0;
    struct node *temp = head;
    while (temp) {
        c++;
        temp = temp->next;
    }
    return c;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    printf("%d", size());
    return 0;
}
