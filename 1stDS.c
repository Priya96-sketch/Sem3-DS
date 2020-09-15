#include <stdio.h>
#include <stdlib.h>
struct Node
{
          int data;
            struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

        new_node->data  = new_data;

        new_node->next = (*head_ref);

        (*head_ref)    = new_node;
}

void insertafter(struct Node* prev_node, int new_data)
{
        if (prev_node == NULL)
        {
                printf("the given previous node cannot be NULL");
                return;
        }

        struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

        new_node->data  = new_data;

        new_node->next = prev_node->next;

        prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data)
{
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        struct Node *last = *head_ref;

        new_node->data  = new_data;

        new_node->next = NULL;

        if (*head_ref == NULL)
        {
                *head_ref = new_node;
                return;
        }

        while (last->next != NULL)
                last = last->next;

                last->next = new_node;
                return;
}

static void reverse(struct Node** head_ref)
{
        struct Node* prev = NULL;
        struct Node* current = *head_ref;
        struct Node* next = NULL;
        while (current != NULL)
        {
                next = current->next;
                current->next = prev;

                prev = current;
                current = next;
        }
        *head_ref = prev;
}
void deleteNode(struct Node **head_ref, int key)
{
            struct Node* temp = *head_ref, *prev;

                if (temp != NULL && temp->data == key)
                {
                        *head_ref = temp->next;
                        free(temp);
                        return;
                }

                while (temp != NULL && temp->data != key)
                {
                        prev = temp;
                        temp = temp->next;
                }

                if (temp == NULL)
                        return;

                prev->next = temp->next;

                free(temp);
}

void delete(struct Node **head_ref, int position)
{
           if (*head_ref == NULL)
                         return;

              struct Node* temp = *head_ref;

                  if (position == 0)
                   {
                        *head_ref = temp->next;
                        free(temp);
                        return;
                   }

                  for (int i=0; temp!=NULL && i<position-1; i++)
                                       temp = temp->next;

                          if (temp == NULL || temp->next == NULL)
                                           return;

                              struct Node *next = temp->next->next;

                                  free(temp->next);

                                      temp->next = next;
}

void printList(struct Node *node)
{
        while (node != NULL)
        {
                printf(" %d ", node->data);
                node = node->next;
        }
}
int main()
{
        struct Node* head = NULL;

        append(&head, 6);

        push(&head, 7);

        push(&head, 1);

        push(&head, 5);

        push(&head, 9);

        printf("\nGiven Linked List:\n ");

        printList(head);

        append(&head, 4);

        printf("\nLinked List After Append: \n");

        printList(head);

        insertafter(head->next, 8);

        printf("\nGiven linked list\n");
        printList(head);
        reverse(&head);
        printf("\nReversed Linked list \n");
        printList(head);
        deleteNode(&head, 1);
                printf("\nLinked List deletion between two nodes: ");
        printList(head);
        delete(&head, 4);
        printf("\nLinked List after Deletion of first position: ");
        printList(head);
        return 0;
}

