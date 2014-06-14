#include<bits/stdc++.h>
using namespace std;
#define NULL 0

struct node
{
struct node *lchild;
int info;
struct node *rchild;
};

struct node *root;

int count;

void insert()
{
    int q;
    int i=1;
    printf("enter number of nodes of tree :\t");
    scanf("%d",&q);
    while(q--)
    {int ikey;
     printf(" (insert one by one ) Enter value %d :\t", i++);
    scanf("%d",&ikey);
    struct node *tmp,*par,*ptr;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        par=ptr;
        if(ikey<ptr->info)
            ptr=ptr->lchild;
        else if(ikey>ptr->info)
            ptr=ptr->rchild;
        else
        {
         printf("\n\nNode already present !!\n\n");
        return;
        }
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=ikey;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    if(par==NULL)
        root=tmp;
    else if(ikey<par->info)
        par->lchild=tmp;
    else
        par->rchild=tmp;

    }
}

void preorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    printf("%d ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
        if(ptr==NULL)
            return;
        inorder(ptr->lchild);
        printf("%d ",ptr->info);
        inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if(ptr==NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->info);
}

int height(struct node *ptr)
{
    int h_left,h_right;
    if(ptr==NULL)
        return 0;
    h_left=height(ptr->lchild);
    h_right=height(ptr->rchild);
    if(h_left> h_right)
        return 1+h_left;
    else
        return 1+h_right;
}

void search()
{
    int skey;
    printf("Enter value to be searched :\t");
    scanf("%d",&skey);
    int flag=0;
    struct node *ptr=root;
    while(ptr!=NULL)
    {
        if(skey<ptr->info)
            ptr=ptr->lchild;
        else if(skey>ptr->info)
            ptr=ptr->rchild;
        else
        {printf("\n\tfound !!!\n");
        flag=1;
        return;}
    }
    if(flag==0)
        printf("\n\tnot found !!!\n");
}

void del()
{
    int dkey;
    printf("Enter valueto be deleted :\t");
    scanf("%d",&dkey);
    struct node *par,*ptr,*child,*succ,*parsucc;
        ptr=root;
        par=NULL;
        while(ptr!=NULL)
        {
            if(dkey==ptr->info)
                break;
            par=ptr;
            if(dkey<ptr->info)
                ptr=ptr->lchild;
            else
                ptr=ptr->rchild;
        }
        if(ptr==NULL)
        {
            printf("value not present in tree");
            return;
        }
        if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
        {
            parsucc=ptr;
            succ=ptr->rchild;
            while(succ->lchild!=NULL)
            {
                parsucc=succ;
                succ=succ->lchild;
            }
            ptr->info=succ->info;
            ptr=succ;
            par=parsucc;
        }
        if(ptr->lchild!=NULL)
        child=ptr->lchild;
        else
            child=ptr->rchild;
        if(par==NULL)
        root=child;
        else if(ptr==par->lchild)
            par->lchild=child;
        else
            par->rchild=child;
        free(ptr);
        return ;
}

void min()
{
    struct node *ptr=root;
    if(ptr!=NULL)
        while(ptr->lchild!=NULL)
            ptr=ptr->lchild;
printf("%d\t",ptr->info);
}

void max()
{
    struct node *ptr=root;
    if(ptr!=NULL)
        while(ptr->rchild!=NULL)
            ptr=ptr->rchild;
printf("%d\t",ptr->info);
}

int main()
{
    printf("\nWelcome to BST Program !!!\n\n");
    int ch;
    do{
        printf("\n1.Insert \n2.Delete \n3.Preorder \n4.Inorder \n5.Postorder \n6.Search \n7.Height \n8.Max Node \n9.Min Node\n10.All 3 Traversals\n0.Exit\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case  2:
                del();
                break;
            case 3:
                printf("\nPreorder :\n\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nInorder :\n\n");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder :\n\n");
                postorder(root);
                printf("\n");
                break;

           case 6:
                search();
                break;
            case  7:
                printf("Height is :\t %d",height(root));
                break;
            case  8:
                max();
                break;
            case  9:
                min();
                break;
            case 10:
                printf("\nPreorder :\n\n");
                preorder(root);
                printf("\n");
                printf("\nInorder :\n\n");
                inorder(root);
                printf("\n");
                printf("\nPostorder :\n\n");
                postorder(root);
                printf("\n\n");
                break;

            case  0:break;

            default:
            printf("\n\nPlease enter correct choice\n\n");
        }
    }while(ch!=0);
}


