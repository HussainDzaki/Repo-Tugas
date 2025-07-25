#include "Boolean.h"
#include "listlinier.h"
#include "stdio.h"
#include "stdlib.h"



int hasloop(List l)
{
    Address slow = l;
    Address fast = l;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            // loop terdeteksi
            slow = l;
            int idx = 0;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
                idx++;
            }
            return idx;
        }
    }
    return IDX_UNDEF;
}

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->info = data;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    Node *a = create_node(1);
    Node *b = create_node(2);
    Node *c = create_node(3);
    Node *d = create_node(3);
    Node *e = create_node(3);
    Node *f = create_node(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = d;

    // a -> b -> c -> NULL

    int cycle_start = hasloop(a);
    if (cycle_start == IDX_UNDEF) {
        printf("Tidak ada siklus.\n");
    }

    printf("ada siklus setalah index : %d\n" , cycle_start);
}