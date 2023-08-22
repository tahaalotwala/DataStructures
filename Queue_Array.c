#include<stdio.h>
#include<stdlib.h>
struct student{
    int roll;
};
struct queue{
    int in,out,max;
    struct student* studarray;
};
char isFull(struct queue* q){
    if(q->in == q->max-1){
        return 1;
    }
    else{
        return 0;
    }
}
char isEmpty(struct queue* q){
    if(q->in < q->out){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue* q,struct student* s){
    q->in++;
    q->studarray[q->in] = *s;
}
struct student dequeue(struct queue* q){
    struct student temp = q->studarray[q->out];
    q->out++;
    return temp;
}
struct student peek(struct queue* q,char ch){
    switch(ch){
        case 1:
        return (q->studarray[q->out]);
        break;
        case 2:
        return (q->studarray[q->in]);
        break;
    }
}
void main(){
    struct queue q1,q2,*qptr;
    struct student *s;
    int q_ch,ch,peek_ch;
    q1.in = q2.in = -1;
    q1.out = q2.out = 0;
    printf("Enter max values of Q1 and Q2\n");
    scanf("%d%d",&q1.max,&q2.max);
    q1.studarray = (struct student*)malloc(q1.max * sizeof(struct student));
    q2.studarray = (struct student*)malloc(q2.max * sizeof(struct student));
    while(1){
        while(1){
            printf("Select queue: \n1.Queue 1\t2.Queue 2\n");
            scanf("%d",&q_ch);
            if(q_ch == 1 || q_ch == 2)
            break;
        }
        qptr = (q_ch == 1)? &q1 : &q2;
        printf("Select operation to be performed:\n");
        printf("1.Enqueue\t2.Dequeue\t3.isFull\t4.isEmpty\t5.Peek\t0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            if(isFull(qptr) == 1){
                printf("Queue is full, cannot enqueue.\n");
            }
            else{
                s = (struct student*)malloc(sizeof(struct student));
                printf("Enter roll no. \n");
                scanf("%d",&s->roll);
                enqueue(qptr,s);
            }
            break;
            case 2:
            if(isEmpty(qptr) == 1){
                printf("Queue is Empty, cannot dequeue.\n");
            }
            else{
                *s = dequeue(qptr);
                printf("Roll no. : %d\n",s->roll);
            }
            break;
            case 3:
            if(isFull(qptr) == 1){
                printf("Queue is full.\n");
            }
            else{
                printf("Queue is not full.\n");
            }
            break;
            case 4:
            if(isEmpty(qptr) == 1){
                printf("Queue is Empty.\n");
            }
            else{
                printf("Queue is not Empty.\n");
            }
            break;
            case 5:
            if(isEmpty(qptr) == 1){
                printf("Queue is Empty, cannot peek.\n");
            }
            else{
                printf("1.Peek at Front\t2.Peek at End:\n");
                scanf("%d",&peek_ch);
                *s = peek(qptr,peek_ch);
                printf("Roll no. : %d\n",s->roll);
            }
            break;
            break;
            case 0:
            return;
            default:printf("Invalid Input\n");
        }
    }
}