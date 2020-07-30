#include <stdio.h>
#include <stdlib.h>


struct list
{
  int data;
  struct list* link;
};


struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  scanf("%d",&(form->data));
  return form;
}


struct list* ptr=0;
struct list* hd=0;


void LinkList()
{
  int n;
  printf("Enter no. elements in your list:");
  scanf("%d",&n);
  printf("Enter data of list\n");
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
    hd = create();
    ptr=hd;
    }else
    {
        ptr->link=create();
        ptr=ptr->link;
    }
  }
  ptr->link=NULL;
  ptr=hd;
}


void printlist(struct list*p)
{
  if(p==hd)
    printf("Your List is:\n");
  if(p!=NULL)
  {
    printf("%d\n",p->data);
    p=p->link;
    printlist(p);
  }
}



void delete()
{
  printf("Enter the element you want to delete\n");
  int n;
  scanf("%d",&n);
  if(n!=hd->data)
  {
    while(ptr->link!=NULL&&n!=ptr->link->data)
    {
      ptr=ptr->link;
    }
    if(ptr->link!=NULL)
    {
        struct list *t = ptr->link;
        ptr->link = ptr->link->link;
        free(t);
    }else
        printf("Wrong Request!!!\n");
  }else
  {
    hd = hd->link;
    free(ptr);
  }
  ptr = hd;
}


int main()
{
  printf(":::::::::::::::::::::Singly-Linked-List:::::::::::::::::::::\n");
  LinkList();
  printlist(ptr);
  delete();
  printlist(ptr);
  return 0;
}
