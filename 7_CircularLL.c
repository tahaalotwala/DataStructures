#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct circularDLL
{
    struct node *head;
};

void traverse(struct circularDLL *list)
{
    struct node *temp = list->head;
    while (temp->next != list->head)
    {
        printf("%d    ", temp->data);
        temp = temp->next;
    }
    printf("%d    \n", temp->data);
}

void insertFront(struct circularDLL *list, struct node *newnode)
{
    newnode->next = list->head;
    newnode->prev = list->head->prev;
    list->head->prev->next = newnode;
    list->head->prev = newnode;
    list->head = newnode;
}

void dltFront(struct circularDLL *list)
{
    list->head->next->prev = list->head->prev;
    list->head->prev->next = list->head->next;
    struct node *temp = list->head;
    free(temp);
    list->head = list->head->next;
}

void insertEnd(struct circularDLL *list, struct node *newnode)
{
    newnode->next = list->head;
    newnode->prev = list->head->prev;
    list->head->prev->next = newnode;
    list->head->prev = newnode;
}

void deleteEnd(struct circularDLL *list)
{
    list->head = list->head->prev;
    dltFront(list);
}

void insertGen(struct circularDLL *list, struct node *n, int pos)
{
    struct node *temp = list->head;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
        if (temp == list->head)
            break;
    }
    if (temp == list->head)
    {
        printf("Invalid Position \n");
        return;
    }
    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
}

void dltGeneral(struct circularDLL *list, int pos)
{
    struct node *temp = list->head;
    pos--;
    int flag = 0;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
        if (temp->next == list->head)
            break;
    }

    if (temp->next == list->head)
    {
        printf("Not Enough Nodes in the list \n");
        return;
    }
    else
    {
        temp->next->next->prev = temp;
        temp = temp->next;
        temp->prev->next = temp->next;
        free(temp);
    }
}

void main()
{
    struct circularDLL list1, list2;
    struct circularDLL *listptr;
    struct node *n;
    int pos;
    int listch, opCode;

    while (1)
    {
        do
        {
            printf("1.List 1     2.List 2\n");
            printf("Select which list to manipulate:\n");
            scanf("%d", &listch);

        } while (listch != 1 && listch != 2);

        listptr = (listch == 1) ? &list1 : &list2;
        printf("Choose operation to be performed:\n");
        printf("1.insertFront    2.Deletefront    3.insertEnd    4.Deleteend    5.Traverse    6.insertGen    7.deleteGen    0.Exit\n");
        scanf("%d", &opCode);
        switch (opCode)
        {
        case 1:
            n = (struct node *)malloc(sizeof(struct node));
            n->next = n->prev = NULL;
            printf("Enter data : ");
            scanf(" %d", &n->data);

            if (listptr->head == NULL)
            {
                n->prev = n;
                n->next = n;
                listptr->head = n;
            }
            else
            {
                insertFront(listptr, n);
            }
            break;
        case 2:
            if (listptr->head == NULL)
            {
                printf("List is empty. Cannot Delete. \n");
            }
            else if (listptr->head->next == listptr->head)
            {
                free(listptr->head);
                listptr->head = NULL;
            }
            else
            {
                dltFront(listptr);
            }
            break;
        case 3:
            n = (struct node *)malloc(sizeof(struct node));
            n->next = n->prev = NULL;
            printf("Enter data : ");
            scanf("%d", &n->data);

            if (listptr->head == NULL)
            {
                n->prev = n;
                n->next = n;
                listptr->head = n;
            }
            else
            {
                insertEnd(listptr, n);
            }
            break;
        case 4:
            if (listptr->head == NULL)
            {
                printf("List is empty. Cannot Delete. \n");
            }
            else if (listptr->head->next == listptr->head)
            {
                free(listptr->head);
                listptr->head = NULL;
            }
            else
            {
                deleteEnd(listptr);
            }
            break;
        case 5:
            if (listptr->head == NULL)
            {
                printf("List is Empty. \n");
            }
            else
            {
                traverse(listptr);
            }
            break;
        case 6:
            n = (struct node *)malloc(sizeof(struct node));
            n->next = n->prev = NULL;
            printf("Enter data : ");
            scanf(" %d", &n->data);

            printf("Enter position : ");
            scanf(" %d", &pos);
            if (listptr->head == NULL && pos == 1)
            {
                n->prev = n;
                n->next = n;
                listptr->head = n;
                break;
            }
            if (listptr->head == NULL && pos != 1)
            {
                printf("Invalid position \n");
                break;
            }
            if (pos == 1 && listptr->head != NULL)
            {
                insertFront(listptr, n);
                break;
            }
            insertGen(listptr, n, pos);
            break;
        case 7:
            if (listptr->head == NULL)
            {
                printf("List is Empty. Cannot delete \n");
                break;
            }
            printf("Enter postion of the node to be deleted : ");
            scanf(" %d", &pos);
            if (listptr->head->next == listptr->head)
            {
                if (pos == 1)
                {
                    listptr->head = NULL;
                }
                else
                {
                    printf("Invalid Position \n");
                }
                break;
            }
            dltGeneral(listptr, pos);
            break;
        case 0:
            return;
            break;
        default:
            printf("Invalid Choice \n");
        }
        if (listptr->head != NULL)
        {
            traverse(listptr);
        }
    }
}
