#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertLast(int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (head == NULL) {
        head = t;
        head->next = head;
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = t;
    t->next = head;
}

void display() {
    if (!head) return;

    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("%d\n", head->data);
}

int main() {
    insertLast(20);
    insertLast(100);
    insertLast(40);
    insertLast(80);
    insertLast(60);

    display();
    return 0;
}
