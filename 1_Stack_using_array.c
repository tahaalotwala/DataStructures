#include<stdio.h>
#include<stdlib.h>

struct student
{
    unsigned int roll;
    unsigned int mark;
};

struct stack
{
    unsigned int MAX;
    unsigned int TOP;
    struct student *studarray;
};

char isFull(struct stack x){
    if(x.TOP == x.MAX){
        return 1;
    }
    return 0;
}
char isEmpty(struct stack x){
    if(x.TOP == 0){
        return 1;
    }
    return 0;
}
struct student peek(struct stack x){
    return (x.studarray[x.TOP]);
}
void push(struct stack *x,struct student s){
    (*x).TOP++;
    (*x).studarray[(*x).TOP] = s;
}
struct student pop(struct stack *x){
    struct student temp = ((*x).studarray[(*x).TOP]);
    (*x).TOP--;
    return temp; 
}
void main()
{
    struct student std;
    struct stack s;
    int choice,flag = 1;
    printf("Enter max no. of students: ");
    scanf("%d",&s.MAX);
    s.TOP = 0;
    s.studarray = (struct student *)malloc((s.MAX+1)*sizeof(struct student));
    while(1)
    {
        printf("Enter choice 1.Push 2.Pop 3.Peek 4.Check if stack is empty 5.Check if stack is full\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(isFull(s) != 1){
                printf("Enter Roll number and marks\n");
                scanf("%u%u",&std.roll,&std.mark);
                push(&s,std);
            }
            else{
                printf("Cannot push into the stack anymore\n");
            }
            break;
            case 2: if(isEmpty(s) != 1){
                std = pop(&s);
                printf("Roll no. : %u \t Marks : %u\n",std.roll,std.mark);
            }
            else{
                printf("Cannot pop from an empty stack\n");
            }
            break;
            case 3: if(isEmpty(s) != 1){
                std = peek(s);
                printf("Roll no. : %u \t Marks : %u \n",std.roll,std.mark);
            }
            else{
                printf("Cannot peek into an empty stack\n");
            }
            break;
            case 4: if(isEmpty(s) == 1){
                printf("Stack is empty.\n");
            }
            else{
                printf("Stack is not empty.\n");
            }
            break;
            case 5: if(isFull(s) == 1){
                printf("Stack is full.\n");
            }
            else{
                printf("Stack is not full.\n");
            }
            break;
            default :flag = 0;
            break;
        }
        if(flag == 0) break;
    }
}
