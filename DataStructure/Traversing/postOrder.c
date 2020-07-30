#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    int data;
}*t1;
struct tree* make(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    printf("Data for this node:\n");
    scanf("%d",&(t->data));
    printf("Enter 1 for adding left child else 0\n");
    scanf("%d",&l);
    if(l)
        t->left=make(t->left);
    else
        t->left = NULL;
    printf("Enter 1 for adding right child else 0\n");
    scanf("%d",&r);
    if(r)
        t->right=make(t->right);
    else
        t->right = NULL;
    return t;
}
void postorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            postorder(t->left);

        if(t->right != NULL)
            postorder(t->right);

        printf("%d\n",t->data);
    }
}

void main()
{
    printf("::::::::::::::::::POST-ORDER METHOD::::::::::::::::::\n");
    t1=make(t1);
    postorder(t1);
}
