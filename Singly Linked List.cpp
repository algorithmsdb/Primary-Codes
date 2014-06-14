#include<bits/stdc++.h>
using namespace std;

int num,loc;

struct node
{
  int a;
  struct node *next;
};
struct node *first,*last;

// first=last=NULL;
void display()
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=first;
  printf("\n");
  if(temp==NULL)
    printf("\n\nlist empty !!\n\n");
  while(temp!=NULL)
  {
    printf("%d\t",temp->a);
    temp=temp->next;
  }
  printf("\n\n");
}

int insert()
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  printf("\n enter value :\n");
  scanf("%d",&temp->a);

  if(first==NULL)
  {
    first=temp;
    first->next=NULL;
  }
  else
  {
    temp->next=first;
    first=temp;
  }
  display();
}

void append()
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
  {
    printf("\n memory not allocated");
  }
  printf("\nenter the value :\n\n");
  scanf("%d",&newnode->a);

  newnode->next=NULL;
  if(first==NULL)
  {
    first=newnode;
  }
  else
  {
    last->next=newnode;
  }
  last=newnode;

}
void del(int num)
{
  struct node *temp,*m;
  temp=first;

  while(temp!=NULL)
  {
    if(temp->a==num)
    {
      if(temp==first)
      {
        first=temp->next;
        free(temp);
      }
      else
      {
        m->next=temp->next;
        free(temp);
      }
    }
    else
    {
      m=temp;
      temp=temp->next;
    }
  }
}
//insert at any position
void insertn(int loc)
{
  int i;
  struct node *temp,*t,*pre;
  pre=first;
  if(loc==1)
  {
    insert();
  }
  else
  {
    for(i=1;i<loc;i++)
    {
      t=pre;
      pre=pre->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nenter the value\n");
    scanf("%d",&temp->a);

temp->next=pre;
t->next=temp;

  }
  display();
}
int search(int num)
{
  struct node *temp;
  temp=first;
  while(temp!=NULL)
  {
    if(temp->a==num)
    {
      printf("%d  found\n\n",num);
      break;
    }
    else
      temp=temp->next;

  }
  if(temp->a!=num)
  {

    printf("\nnot found\n\n");
  }
}
void rev()
{
     struct node *p1,*p2,*p3;
  p1=first;
  p2=NULL;
  while(p1!=NULL)
  {
    p3=p2;
    p2=p1;
    p1=p1->next;
    p2->next=p3;
  }
  first=p2;
  display();
}


void sort()
{
    printf("before sorting :\n\n");
    display();
    struct node *temp,*n;
    int i,j,size,loc;
    size=0;
    temp=first;
    while(temp!=NULL)
        {size++;
        temp=temp->next;
        }
    temp=first;
    for(i=0;i<size;i++)
    {
        for(j=0;j<(size-1);j++)
        {
            if((temp->a)>(temp->next->a))
            {
                loc=temp->a;
                temp->a=temp->next->a;
                temp->next->a=loc;
            }
            temp=temp->next;
        }
        temp=first;
    }
    printf("after sorting :\n\n");
    display();
}
void evenposelm()
{
      printf("\n\n");
    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
    temp=first;
   int counter=1;
   while(temp!=NULL)
   {
       if(counter%2==1)
       {
          counter++;
          temp=temp->next;
       }
       if(counter%2==0)
       {
           printf("%d\t",temp->a);
          counter++;
        temp=temp->next;

       }
   }
     printf("\n\n");
     printf("\n\n");

}
void oddposelm()
{
      printf("\n\n");
    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
    temp=first;
   int counter=1;
   while(temp!=NULL)
   {
       if(counter%2==1)
       {
           printf("%d\t",temp->a);
          counter++;
        temp=temp->next;

       }
       if(counter%2==0)
       {
           counter++;
          temp=temp->next;

       }
   }
     printf("\n\n");
}
void mid()
{
    printf("\n");
    struct node *temp1,*temp2,*temp3;
    temp1=first;
    temp2=first;
    while(temp2!=NULL)
    {
        temp2=temp2->next;
        if(temp2!=NULL)
        {
            temp2=temp2->next;
            temp1=temp1->next;
        }
    }
    printf("mid element is :\t\t %d",temp1->a);
         printf("\n\n");

}
void deleteall()
{
    first=last=NULL;
    printf("\n\nall deleted !!\n\n");
}


int main()
{
  int ch;
  do
  {
    printf("\nEnter the choice \n\n1.append (at end) \n2.display \n3.Insert (at starting) \n4.delete \n5.insert at any position \n6.Search \n7.reverse \n8.sort\n9.print even elements\n10.print odd elements\n11.mid element\n12.delete all\n111.exit \n\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        append();
        break;
      case 2:
        display();
        break;
      case 3:
        insert();
        break;
      case 4:
        printf("\nenter the value : \n");
        scanf("%d",&num);
        del(num);
        break;
      case 5:
        printf("\n enter the location \n");
        scanf("%d",&loc);
        insertn(loc);
        break;
      case 6:
        printf("\nenter the value to find \n");
        scanf("%d",&num);
        search(num);
        break;
      case 7:
        rev();
        break;
      case 8:
        sort();break;
      case 9:
        evenposelm();
        break;
      case 10:
        oddposelm();
        break;
      case 11:
        mid();
        break;
      case 12:
        deleteall();
      default:
        break;
    }
  }while(ch!=111);
}

