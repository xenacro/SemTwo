#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    char data;
}*t1;
struct tree* form(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    fflush(stdin);
    scanf("%c",&(t->data));
    printf("Enter 1 if node rooted at %c has left child else 0\n",t->data);
    scanf("%d",&l);
    if(l)
    {
        printf("Enter data of left child rooted at %c\n",t->data);
        t->left=form(t->left);
    }
    else
        t->left = NULL;
    printf("Enter 1 if node rooted at %c has right child else 0\n",t->data);
    scanf("%d",&r);
    if(r)
    {
        printf("Enter data of right child rooted at %c\n",t->data);
        t->right=form(t->right);
    }
    else
        t->right = NULL;
    return t;
}

void preorder(struct tree *t)
{
    if(t != NULL)
    {
        printf("%c\n",t->data);
        if(t->left != NULL)
            preorder(t->left);

        if(t->right != NULL)
            preorder(t->right);
    }
}


int node(struct tree *t)
{
    if(t)
        return 1 + node(t->left) + node(t->right);
    else
        return 0;
}

int main()
{
    printf(":::::::::::::::::Tree-Creation::::::::::::::::::\n");
    t1=form(t1);
    printf("::::::::::::::::::PRE-ORDER METHOD::::::::::::::::::\n");
    preorder(t1);
    printf("The Number of Nodes in tree: %d\n",node(t1));
    return 0;
}


