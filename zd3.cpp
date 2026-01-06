#include <stdio.h>
struct Node
{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
int a[] = {5, 2, 3 ,4, 5};

void creat(Node * head)
{
    Node* tail = head;
    for(int i = 0; i <= 4; i ++)
    {
        Node* p = new Node(a[i]);
        tail = tail->next = p;
    }
}

int main()
{
    Node* head = new Node(-1);
    creat(head);

    Node* t = head;
    while(t -> next != NULL)
    {
        t = t->next;
        printf("%d ", t->val);
    }

    return 0;
}