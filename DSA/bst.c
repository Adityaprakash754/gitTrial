#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * llink;
    int info;
    struct node * rlink;
};
typedef struct node * NODE;

NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated\n");
        exit(0);
    }

    return x;
}

NODE insert_bst(NODE root,int info)
{
    NODE temp;
    temp=getNode();
    temp->info=info;
    temp->llink=temp->rlink=NULL;

    if(root==NULL)
    return temp;

    NODE prev,cur;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;

        if(info < cur->info)
        cur=cur->llink;
        else
        cur=cur->rlink;
    }

    if(info < prev->info)
    prev->llink=temp;
    else
    prev->rlink=temp;

    return root;
}