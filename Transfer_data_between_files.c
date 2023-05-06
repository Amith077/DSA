#include<stdio.h>
FILE *fp,*fp2;
void readfile(FILE *fp1)
{
    char ch;
    printf("Contents written in the file is\n");
    while(!feof(fp1))
    {
        ch=fgetc(fp1);
        printf("%c",ch);
    }
}

void transfer(FILE *fp1,FILE *fp2)
{
    char ch;
    printf("Contents written in the file is\n");
    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch,fp2);
    }

}

void compareFiles(FILE *file1, FILE *file2){
   char ch1 = getc(file1);
   char ch2 = getc(file2);
   int error = 0, pos = 0, line = 1;
   while (ch1 != EOF && ch2 != EOF){
      pos++;
      if (ch1 == ' ' && ch2 == ' '){
         line++;
         pos = 0;
      }
      if (ch1 != ch2){
         error++;
         printf("Line Number : %d \tError" " Position : %d ", line, pos);
      }
      ch1 = getc(file1);
      ch2 = getc(file2);
   }
   printf("Total Errors : %d\t", error);
}

void main()
{
    char t[5]=".txt";
    int o;
    char fname[30];
    do{
        printf("1.Create a new file\n");
        printf("2.Read data from the file\n");
        printf("3.Transfer the data to another file\n");
        printf("4.Print status of the transfer\n");
        printf("5.Exit\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                    printf("Enter the name of the file\n");
                    scanf("%s",&fname);
                    strcat(fname,t);
                    fp=fopen(fname,"w");
                    if(fp!=NULL)
                    {
                        printf("File created with the name:%s\n",fname);
                    }
                    fclose(fp);
                    break;
            case 2: fp=fopen("sample1.txt","r");
                    readfile(fp);
                    fclose(fp);
                    break;
            case 3: printf("Transfering data...\n");
                    fp=fopen(fname,"w");
                    fp2=fopen("sample1.txt","r");
                    transfer(fp2,fp);
                    fclose(fp);
                    fclose(fp2);
                    break;

            case 4: fp=fopen(fname,"r");
                    fp2=fopen("sample1.txt","r");
                    compareFiles(fp,fp2);
                    fclose(fp);
                    fclose(fp2);
                    break;

            case 5: exit(0);
                    break;

        }
    }while(o!=5);
    printf("BYE BYE\n");
}
