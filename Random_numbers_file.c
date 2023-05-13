#include<stdio.h>
#include<stdlib.h>

FILE *fp;   //file pointer

void random(FILE *f,int n)  //function to generate random numbers
{
    int num;
    for(int i=0;i<n;i++)
    {
        num=rand()%100;
        fprintf(f,"%d ",num);
    }
}
void main()
{
    int num;
    fp=fopen("Random_numbers.txt","w");
    if(fp!=NULL)
    {
        printf("File has been created\n");
    }
    printf("Enter how many random numbers you want\n");
    scanf("%d",&num);
    random(fp,num);
    fclose(fp);
    printf("%d random numbers have been generated in file",num);
}
