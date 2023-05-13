#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL,temp,cur,newn;

void insert(FILE *fp,int n)               //UDF TO INSERT A NUMBER IN THE FILE
{
    int d;
    for(int i=0;i<n;i++)
    {
        newn=(node)malloc(sizeof(struct NODE));          // ALLOCATING MEMORY FOR THE NEWNODE FOR THE DATA TO BE INSERTED
        fscanf(fp,"%d",&d);
        newn->data=d;
        newn->next=NULL;
        if(head==NULL)
        {
            head=newn;
        }
        else
        {
            temp=head;
            head=newn;
            head->next=temp;
        }
    }
}

void display()                        // UDF TO DISPLAY THE CONTENT OF THE STRUCTURE
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void sort()                     // UDF TO SORT THE NUMBER IN THE LINKED LIST
{
    cur=head;
    while(cur->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->data > temp->data)
            {
                int x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;
            }
            temp=temp->next;
        }
        cur=cur->next;
    }
}

main()
{
    FILE *fp;
    int n;
    printf("Enter total numbers: ");
    scanf("%d",&n);
    fp=fopen("sort.txt","r");             // OPENING THE FILE "sort.txt" TO READ THE DATA FROM IT
    insert(fp,n);
    sort();
    display();
    fclose(fp);
}
