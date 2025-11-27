#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *prev, *next;
};

struct node* createNode(char c) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = c;
    t->prev = t->next = NULL;
    return t;
}

int isPalindrome(struct node* head) {
    if (!head) return 1;

    struct node *left = head, *right = head;
    while (right->next) right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data) return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main() {
    struct node *head = createNode('r');
    head->next = createNode('a'); head->next->prev = head;
    head->next->next = createNode('d'); head->next->next->prev = head->next;
    head->next->next->next = createNode('a'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode('r'); head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
