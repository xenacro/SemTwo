#include <stdio.h>
#include <stdlib.h>
struct list
{
  struct list *pre;
  int data;
  struct list *next;
};


struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  scanf("%d",&(form->data));
  form->pre = ptr;
  return form;
}

struct list *hd,*ptr;

void LinkList()
{
  int n;
  printf("Enter no. of elements in your list:");
  scanf("%d",&n);
  printf("Enter data for lists:");
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
    hd = create();
    ptr=hd;
    }else
    {
        ptr->next=create();
        ptr=ptr->next;
    }
  }
  ptr->next=NULL;
  ptr=hd;
}


void delete()
{
  printf("Enter the element you want to Delete:");
  int n;
  scanf("%d",&n);
  if(n!=hd->data)
  {
    while(ptr->next!=NULL&&n!=ptr->next->data)
    {
      ptr=ptr->next;
    }
    if(ptr->next!=NULL)
    {
        struct list *t = ptr->next;
        ptr->next = ptr->next->next;
        if(t->next!=NULL)
        ptr->next->pre=ptr;
        free(t);
    }else
        printf("Wrong Request!!!\n");
  }else
  {
    hd = hd->next;
    hd->pre=NULL;
    free(ptr);
  }
  ptr = hd;
}


void printlist(struct list* ptr)
{
  printf("Your list(forward direction):\n");
  while(ptr->next!=NULL)
  {
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
  printf("%d\n",ptr->data);
  printf("Your list(backward direction):\n");
  while(ptr->pre)
  {
    printf("%d ",ptr->data);
    ptr = ptr->pre;
  }
  printf("%d\n",ptr->data);
}



int main()
{
  printf(":::::::::::::::::::::Doubly-Linked-List:::::::::::::::::::::\n");
  LinkList();
  printlist(ptr);
  delete();
  printlist(ptr);
}
