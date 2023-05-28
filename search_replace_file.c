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


void replacefile(FILE *fp)
{
    char x[50];
    while(!feof(fp))
    {
        while(fscanf(fp," %1023s",x)==1)
        {

            puts(x);
            printf("%s ",x);
        }
    }

}
void main()
{
    char find1[50], replace[50];
    fptr=fopen("source.txt","r");

    printf("Enter the word you want to replace\n");
    scanf("%s",find1);
    printf("Entered word is %s\n",find1);

    printf("Enter the word you want to replace with\n");
    scanf("%s",replace);
    printf("Entered word is %s\n",replace);

    replacefile(fptr);
    fclose(fptr);




}
