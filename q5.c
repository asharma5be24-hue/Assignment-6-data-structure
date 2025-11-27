#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int x) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    return t;
}

int isCircular(struct node* head) {
    if (head == NULL) return 1;
    struct node* t = head->next;
    while (t != NULL && t != head)
        t = t->next;
    return t == head;
}

int main() {
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    /* make this circular */
    head->next->next->next = head;

    if (isCircular(head))
        printf("Circular");
    else
        printf("Not Circular");

    return 0;
}
