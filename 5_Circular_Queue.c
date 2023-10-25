#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int f, r, max;
    int *arr;
};

char isFull(struct Queue *q)
{
    if (q->f == (q->r + 1) % (q->max + 1))
    {
        return 1;
    }
    return 0;
}

char isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int *n)
{
    q->r = (q->r + 1) % (q->max + 1);
    q->arr[q->r] = *n;
}

int *dequeue(struct Queue *q)
{
    q->f = (q->f + 1) % (q->max + 1);
    return &q->arr[q->f];
}

int *peek(struct Queue *q, char ch)
{
    if (ch == 1)
    {
        return &q->arr[(q->f + 1) % (q->max + 1)];
    }
    return &q->arr[q->r];
}

int main()
{
    struct Queue q1, q2;
    q1.arr = q2.arr = NULL;
    struct Queue *qptr = NULL;
    int q_ch, choice, peekChoice;
    int *n, n1;
    printf("Enter max size of Queue 1 and Queue 2 : \n");
    scanf(" %d%d", &q1.max, &q2.max);

    q1.arr = (int *)malloc((q1.max + 1) * sizeof(int));
    q2.arr = (int *)malloc((q2.max + 1) * sizeof(int));
    q1.f = q1.r = q2.f = q2.r = 0;

    while (1)
    {
        do
        {
            printf("Select the queue you want to operate on : \n");
            printf("1. Queue 1      2. Queue 2\n");
            scanf(" %d", &q_ch);

        } while (q_ch != 1 && q_ch != 2);
        qptr = (q_ch == 1) ? &q1 : &q2;

        printf("1.Enqueue    2.Dequeue    3.Peek    4.isFull    5.isEmpty    0.Exit\n");
        printf("Enter your choice : ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(qptr) == 1)
            {
                printf("Cannot Enqueue. Queue is Full \n");
                break;
            }
            printf("Enter value to be enqueued : ");
            scanf("%d", &n1);

            enqueue(qptr, &n1);
            break;
        case 2:
            if (isEmpty(qptr) == 1)
            {
                printf("Queue is Empty. Cannot Dequeue. \n");
                break;
            }
            n = dequeue(qptr);
            printf("Dequeued element : %d \n", *n);
            break;
        case 3:
            if (isEmpty(qptr) == 1)
            {
                printf("Queue is Empty. Cannot Peek. \n");
                break;
            }
            printf("1.front    2.rear \n");
            printf("Which end do you want to peek : ");
            scanf(" %d", &peekChoice);

            n = peek(qptr, peekChoice);
            printf("Element : %d \n", *n);
            break;
        case 4:
            if (isFull(qptr) == 1)
            {
                printf("Queue is Full \n");
                break;
            }
            printf("Queue is NOT Full \n");
            break;
        case 5:
            if (isEmpty(qptr) == 1)
            {
                printf("Queue is Empty. \n");
                break;
            }
            printf("Queue is NOT Empty. \n");
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}
