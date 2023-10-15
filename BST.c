#include <stdio.h>
#include <stdlib.h>
int key;
struct node
{
    int data;
    struct node *l, *r;
};
struct bst
{
    struct node *root;
};

void traverse(struct node *n)
{
    if (n == NULL)
    {
        printf("\n");
        return;
    }
    traverse(n->l);
    printf(" %d ", n->data);
    traverse(n->r);
}

void insert(struct bst *t, struct node *newNode) // iterative
{
    struct node *cnp;
    cnp = t->root;

    while (1)
    {
        if (newNode->data <= cnp->data)
        {
            if (cnp->l != NULL)
            {
                cnp = cnp->l;
            }
            else
            {
                cnp->l = newNode;
                return;
            }
        }
        else
        {
            if (cnp->r != NULL)
            {
                cnp = cnp->r;
            }
            else
            {
                cnp->r = newNode;
                return;
            }
        }
    }
}

struct node *find(struct node *root)
{
    struct node *cnp = root;
    while (1)
    {
        if (cnp == NULL)
        {
            return NULL;
        }
        if (cnp->data == key)
        {
            return cnp;
        }
        if (key < cnp->data)
        {
            cnp = cnp->l;
        }
        else
        {
            cnp = cnp->r;
        }
    }
}

struct node *findP(struct node *root)
{
    struct node *cnp;
    cnp = root;
    struct node *pcnp = cnp;
    while (1)
    {
        if (key == cnp->data)
        {
            return pcnp;
        }
        if (key < cnp->data)
        {
            if (cnp->l != NULL)
            {
                pcnp = cnp;
                cnp = cnp->l;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if (cnp->r != NULL)
            {
                pcnp = cnp;
                cnp = cnp->r;
            }
            else
            {
                return NULL;
            }
        }
    }
}

void delete(struct node *n, struct node *pn)
{
    struct node **temp;

    if (pn->l == n)
    {
        temp = &(pn->l);
    }
    else
    {
        temp = &(pn->r);
    }

    if (n->l == NULL && n->r == NULL)
    {
        free(n);
        *temp = NULL;
        return;
    }

    if (n->l == NULL || n->r == NULL)
    {
        if (n->r != NULL)
        {
            *temp = n->r;
            free(n);
            return;
        }
        if (n->l != NULL)
        {
            *temp = n->l;
            free(n);
            return;
        }
    }

    struct node *rep = n->r;
    if (rep->l == NULL)
    {
        n->data = rep->data;
        n->r = rep->r;
        return;
    }
    while (rep->l->l != NULL)
    {
        rep = rep->l;
    }
    n->data = rep->l->data;
    rep->l = NULL;
}

void main()
{
    struct bst tree;
    tree.root = NULL;
    struct node *temp, *temp2;
    struct node *n;
    int ch;

    while (1)
    {
        printf("Enter choice:\n");
        printf("1.Insert    2.Search    3.Delete    4.Traverse    0.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            n = (struct node *)malloc(sizeof(struct node));
            printf("Enter data to be inserted : \n");
            scanf("%d", &n->data);
            n->l = NULL;
            n->r = NULL;

            if (tree.root == NULL)
            {
                tree.root = n;
            }
            else
            {
                insert(&tree, n);
            }
            break;
        case 2:
            if (tree.root == NULL)
            {
                printf("Cannot search in an empty tree \n");
                break;
            }
            else
            {
                printf("Enter data to be searched : ");
                scanf("%d", &key);
                temp = find(tree.root);
                if (temp != NULL)
                {
                    printf("Data found : %d\n", temp->data);
                }
                else
                {
                    printf("data not found\n");
                }
            }
            break;
        case 3:
            if (tree.root == NULL)
            {
                printf("Cannot delete from an empty tree \n");
                break;
            }
            else
            {
                printf("Enter data to be deleted : ");
                scanf("%d", &key);
                temp = find(tree.root);
                if (temp == tree.root)
                {
                    if (temp->l == NULL)
                    {
                        tree.root = tree.root->r;
                        break;
                    }
                    else if (temp->r == NULL)
                    {
                        tree.root = tree.root->l;
                        break;
                    }
                }
                if (temp != NULL)
                {
                    temp2 = findP(tree.root);
                    delete (temp, temp2);
                }
                else
                {
                    printf("data not found\n");
                }
            }
            break;
        case 4:
            if (tree.root == NULL)
            {
                printf("Cannot traverse an empty tree \n");
                break;
            }
            else
            {
                traverse(tree.root);
            }
            break;
        case 0:
            return;
            break;
        default:
            printf("Invalid Choice");
        }
    }
}