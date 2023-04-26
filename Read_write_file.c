#include<stdio.h>
FILE *fptr;
void printfile(int a)
{
    printf("Enter the %d values\n",a);
    int val;
    for(int i=0;i<a;i++)
    {
        scanf("%d",&val);
        fprintf(fptr,"%d ",val);
    }
    printf("Write to file is successful\n");
}
void readfile()             // reads data per character from the file
{
    char ch;
    printf("Contents written in the file is\n");
    while(!feof(fptr))
    {
        ch=fgetc(fptr);
        printf("%c",ch);
    }
}
void main()
{
    int count;

    fptr=fopen("sample1.txt","w");
    printf("Enter size\n");
    scanf("%d",&count);
    printfile(count);

    fclose(fptr);

    fptr=fopen("sample1.txt","r");
    readfile();

}
