#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"merge_email.c"
#include"merge_phone.c"
#include"similar_email.c"
#include"similar_phone.c"
#include"add_remove_email.c"
#include"add_remove_phone.c"
#include"string_compare.c"

struct data_base
{
  char name[50];	
  char phone1[11];
  char phone2[11];
  char email[50];
  char address[175];
  char occupation[20];
  char dob[11];
};

void print2D(char array2d[7][175])
{
  array2d[0][strlen(array2d[0])]='\0';
  array2d[1][10]='\0';
  printf("Name                : %s",array2d[0]);
  printf("\nPhone Number        : %s",array2d[1]);
  if(array2d[2][0]!='-')
  {
    array2d[2][10]='\0';
    printf("\n                      %s",array2d[2]);
  }
  if(array2d[3][0]!='-')
    printf("\nEmail Address       : %s",array2d[3]);
  if(array2d[4][0]!='-')
    printf("\nResidential Address : %s",array2d[4]);
  if(array2d[5][0]!='-')
    printf("\nOccupation          : %s",array2d[5]);
  if(array2d[6][0]!='-')
  {
    array2d[6][10]='\0';
    printf("\nDate of Birth       : %s",array2d[6]);
  }
  printf("\n\n");
}

int main(void)
{
  FILE* fp=fopen("data_base.txt","a+");
  int preference, n;
  printf("Enter the number of contact you wish to add in the Directory : ");
  scanf("%d",&n);
  printf("\nNOTE :\n1)Enter '-' if you do not wish to enter that particular type of information into the Directory.\n");
  printf("2)Strings of name, occupation and address need to be separated by '-'\n");
  struct data_base info;
  while(n>0)	
  {
    printf("Enter full name : ");
    scanf("%s",info.name);
    fputs(info.name,fp);
    fprintf(fp,"\t");
    printf("Enter the 1st phone number : ");
    scanf("%s",info.phone1);
    if(merge_phone(info.phone1)==1)
    {
      printf("This telephone number already exists in the Directory.\n\n");
      printf("The following are the details of that contact: \n\n");
      similar_phone(info.phone1);
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
      add_remove(info.phone1);
      goto label;
    }
    else
    {
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the 2nd phone number : ");
    scanf("%s",info.phone2);
    if(merge_phone(info.phone2)==1 && info.phone2[0]!='-')
    {
      printf("This telephone number already exists in the directory.\n");
      printf("The following are the details of that contact: \n\n");
      similar_phone(info.phone2);
      fputs(info.phone2,fp);
      fprintf(fp,"\t");
      add_remove_phone(info.phone2);
      goto label;
    }
    else
    {
      fputs(info.phone2,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the email address    : ");
    scanf("%s",info.email);
    if(merge_email(info.email)==1 && info.email[0]!='-')
    {
      printf("This email already exists in thre directory");
      printf("The following are the details of that contact: \n\n");
      similar_email(info.email);
      fputs(info.email,fp);
      fprintf(fp,"\t");
      add_remove_email(info.email);
      goto label;
    }
    else
    {
      fputs(info.email,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the residential address : ");
    scanf("%s",info.address);
    fputs(info.address,fp);
    fprintf(fp,"\t");
    printf("Enter the occupation          : ");
    scanf("%s",info.occupation);
    fputs(info.occupation,fp); 
    fprintf(fp,"\t");
    printf("Enter the date of birth in dd/mm/yyyy format : ");
    scanf("%s",info.dob);
    fputs(info.dob,fp); 
    fprintf(fp,"\t");
    fprintf(fp,"\n");
    label: n--;
           if(n>0)
           {
             printf("Do you want to continue (Press 1 for YES and Press 0 for NO) : ");
             scanf("%d",&preference);
             if(preference==0)
               break;
             else if(preference!=1 && preference!=0)
             {
               printf("You are requested to give a proper response\n");
               scanf("%d",&preference);
	       if(preference==1)
                 continue;
               else
	         break;
             }
             else if(n==0)
               break;
             else
               continue;
           }	 
  } 
  printf("*****Data Accepted Successfully*****\n");
  fclose(fp);
  return 0;
}
