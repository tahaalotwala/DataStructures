#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node* next;
};
struct stack{
    struct node* top;
};
void push(struct stack* list,struct node* elmt){
    elmt->next = list->top;
    list->top = elmt;
}
struct node * pop(struct stack* list){
    struct node* temp = list->top;
    list->top = list->top->next;
    return temp;
}
char isEmpty(struct stack* s){
    if((*s).top == NULL) return 1;
    else return 0;
}
struct node* peek(struct stack* s){
    return ((*s).top);
}
int main(){
    struct stack stack1,stack2;
    stack1.top = stack2.top = NULL;
    struct stack* stackptr = NULL;
    int stackch,actionch,pos;
    struct node* node;
    struct node* temp;
    while(1){
        do{
            printf("Select the Stack to operate on:\n1.stack 1 \t 2.stack 2\n");
            scanf("%d",&stackch);
        }while(stackch!=1 && stackch!=2);
        stackptr = (stackch == 1)? &stack1 : &stack2;
        printf("Choose operation to be performed:\n");
        printf("1.push \t 2.pop \t 3.Peek \t 4.isEmpty\n");
        scanf("%d",&actionch);
        switch(actionch){
            case 1:
            node = (struct node*)malloc(sizeof(struct node));
            if(node != NULL){
                printf("Enter the data  to be pushed: ");
			    scanf("%d", &((*node).data ));
                (*node).next = NULL;
                if((*stackptr).top == NULL){
                (*stackptr).top = node;
                }
                else push(stackptr,node);
            }
            else printf("Not Enough memory.Malloc Failed\n");
            break;
            case 2:
            if((*stackptr).top==NULL){
					printf("Stack is empty. Cannot POP");
				}
				else{
                        struct node *temp = pop(stackptr);
                        printf("Element popped is: %d\n",temp->data);
                }
                break;
            case 3:
            temp = peek(stackptr);
            if(isEmpty(stackptr) == 0) printf("Element at the top is: %d\n",temp->data);
            else printf("Stack is empty\n");
            break;
            case 4:
            if(isEmpty(stackptr) == 1) printf("Stack is empty\n");
            else printf("Stack is NOT empty\n");
            break;
            default: return 0;
        }
    }
}