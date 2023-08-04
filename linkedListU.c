#include<stdio.h>
#include<stdlib.h>
struct node{
    int roll;
    struct node* next;
};
struct sll{
    struct node* head;
};
void traverse(struct sll ptr){
    while(ptr.head!=NULL){
        printf("%5d",ptr.head->roll);
        ptr.head = ptr.head->next;
    }
    printf("\n");
}
void addfront(struct sll* list,struct node* elmt){
    elmt->next = list->head;
    list->head = elmt;
}
void deletefront(struct sll* list){
    struct node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}
void deleteend(struct sll* list){
    struct node* nodeptr = list->head;
    while(nodeptr->next->next != NULL){
        nodeptr = nodeptr->next;
    }
    struct node* nodeptr2 = nodeptr->next;
    nodeptr->next = NULL;
    free(nodeptr2);
}
void addend(struct sll* list,struct node* elmt){
    struct node* nodeptr = list->head;
    while(nodeptr->next != NULL){
        nodeptr = nodeptr->next;
    }
    nodeptr->next = elmt;
    elmt->next = NULL;
}
void delpos(struct sll* x,int k){
    struct node* mp,*temp;
    mp = x->head;
    while(mp!=NULL && k!=1){
        mp = mp->next;
        k--;
    }
    if(k>1) printf("Position is greater than size of the list\n");
    else{
        temp = mp->next->next;
        free(mp->next);
        mp->next = temp;
    }
}
void addpos(struct sll *x, struct node* s, int k) {
    struct node *mp, *temp;
    mp = x->head;
    while (mp->next != NULL && k!=1){
        mp = mp->next;
        k--;
    }
    if (k>1){
        printf("Position is greater than size of the list.\n");
    } 
    else{
        temp = mp->next;
        mp->next = s;
        s->next = temp;
    }
}
int main(){
    struct sll list1,list2;
    list1.head = list2.head = NULL;
    struct sll* listptr = NULL;
    int listch,actionch,pos;
    struct node* node;
    while(1){
        do{
            printf("Select the list to operate on:\n1.List 1 \t 2.List 2\n");
            scanf("%d",&listch);
        }while(listch!=1 && listch!=2);
        listptr = (listch == 1)? &list1 : &list2;
        printf("Choose operation to be performed:\n");
        printf("1.Addfront\t2.Deletefront\t3.Addend\t4.Deleteend\t5.Traverse\t6.Addgeneral\t7.Deletegeneral\n");
        scanf("%d",&actionch);
        switch(actionch){
            case 1:
            node = (struct node*)malloc(sizeof(struct node));
            printf("Enter the rollnumber of new node: ");
			scanf("%d", &((*node).roll));
            (*node).next = NULL;
            if((*listptr).head == NULL){
                (*listptr).head = node;
            }
            else    addfront(listptr,node);
            break;
            case 2:
            if( (*listptr).head==NULL){
					printf("Selected list is empty. Can not delete from the front of the list.\n");
				}
				else    deletefront(listptr);
                break;
            case 3:
            node = (struct node*)malloc(sizeof(struct node));
            printf("Enter the rollnumber of new node: ");
			scanf("%d", &((*node).roll));
            (*node).next = NULL;
            if((*listptr).head == NULL){
                (*listptr).head = node;
            }
            else    addend(listptr,node);
            break;
            case 4:
            if(listptr->head == NULL)
            printf("cannot delete from an empty list\n");
            else{
                if((*((*listptr).head)).next==NULL)
                {
                    free((*listptr).head);
					(*listptr).head=NULL;
                }
                else{
                    deleteend(listptr);
                }
            }
            break;
            case 5:
			if( (*listptr).head == NULL )
			printf("Empty list\n");
            break;
            case 6:
            node = (struct node*)malloc(sizeof(struct node));
            printf("Enter the rollnumber of new node: ");
			scanf("%d", &((*node).roll));
            (*node).next = NULL;
            printf("Enter position: ");
            scanf("%d",&pos);
            pos--;
            addpos(listptr,node,pos);
            break;
            case 7:
            printf("Enter position: ");
            scanf("%d",&pos);
            pos--;
            delpos(listptr,pos);
            break;
            default: return 0;
        }
        if((*listptr).head != NULL)
			traverse(*listptr);
    }
}