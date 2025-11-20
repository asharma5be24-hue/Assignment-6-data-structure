#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* newNode(int x) {
    struct node* t = malloc(sizeof(struct node));
    t->data = x;
    t->prev = t->next = NULL;
    return t;
}

void insertFirst(int x) {
    struct node* t = newNode(x);
    if (!head) {
        head = t;
        head->next = head->prev = head;
    } else {
        struct node* last = head->prev;
        t->next = head;
        t->prev = last;
        last->next = t;
        head->prev = t;
        head = t;
    }
}

void insertLast(int x) {
    struct node* t = newNode(x);
    if (!head) {
        head = t;
        head->next = head->prev = head;
    } else {
        struct node* last = head->prev;
        last->next = t;
        t->prev = last;
        t->next = head;
        head->prev = t;
    }
}

void insertAfter(int key, int x) {
    if (!head) return;
    struct node* temp = head;
    do {
        if (temp->data == key) {
            struct node* t = newNode(x);
            t->next = temp->next;
            t->prev = temp;
            temp->next->prev = t;
            temp->next = t;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void insertBefore(int key, int x) {
    if (!head) return;
    if (head->data == key) {
        insertFirst(x);
        return;
    }
    struct node* temp = head->next;
    while (temp != head) {
        if (temp->data == key) {
            struct node* t = newNode(x);
            t->next = temp;
            t->prev = temp->prev;
            temp->prev->next = t;
            temp->prev = t;
            return;
        }
        temp = temp->next;
    }
}

void deleteNode(int key) {
    if (!head) return;
    struct node* temp = head;

    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                head = NULL;
                free(temp);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

int search(int key) {
    if (!head) return 0;
    struct node* temp = head;
    do {
        if (temp->data == key) return 1;
        temp = temp->next;
    } while (temp != head);
    return 0;
}

void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int ch, x, key;
    while (1) {
        printf("\n1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n5 Delete Node\n6 Search\n7 Display\n8 Exit\n");
        scanf("%d", &ch);
        if (ch == 8) break;

        switch (ch) {
            case 1: scanf("%d", &x); insertFirst(x); break;
            case 2: scanf("%d", &x); insertLast(x); break;
            case 3: scanf("%d %d", &key, &x); insertAfter(key, x); break;
            case 4: scanf("%d %d", &key, &x); insertBefore(key, x); break;
            case 5: scanf("%d", &key); deleteNode(key); break;
            case 6: scanf("%d", &key); 
                    if (search(key)) printf("Found\n"); 
                    else printf("Not Found\n");
                    break;
            case 7: display(); break;
        }
    }
    return 0;
}
