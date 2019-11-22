#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
  array2d[1][10]='\0';
  for(int i=1;i<=24+strlen(array2d[0]);i++)
    printf("✯");
  printf("\n Name                : %s",array2d[0]);
  printf("\n Phone Number        : %s",array2d[1]);
  if(array2d[2][0]!='-')
  {
    array2d[2][10]='\0';
    printf("\n                       %s",array2d[2]);
  }
  if(array2d[3][0]!='-')
    printf("\n Email Address       : %s",array2d[3]);
  if(array2d[4][0]!='-')
    printf("\n Residential Address : %s",array2d[4]);
  if(array2d[5][0]!='-')
    printf("\n Occupation          : %s",array2d[5]);
  if(array2d[6][0]!='-')
  {
    array2d[6][10]='\0';
    printf("\n Date of Birth       : %s",array2d[6]);
  }
  printf("\n");
  for(int i=1;i<=24+strlen(array2d[0]);i++)
    printf("✯");
  printf("\n\n");
}

int string_compare(char array1[100], char array2[100])
{
  int compare=0, count=0, i;
  if(strlen(array1)==strlen(array2))
  {
    for(i=0;i<strlen(array1);i++)
    {
      if(array1[i]==array2[i] || abs((int)array1[i]-(int)array2[i])==32)
      count++;
    }
    if(count!=strlen(array1))
      compare=1;
  }
  else
    compare=1;
  return compare;
}


void similar_phone(char phone_input[])
{
  FILE* fp=fopen("data_base.txt","r");
  char single_contact[2000];
  char details[7][175], separate[6][50];
  int row, column, dashes, i, j, r, c;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    details[1][10]='\0';
    details[2][10]='\0';
    if(string_compare(details[1],phone_input)==0 || string_compare(details[2],phone_input)==0)
    {
      print2D(details);
      break;
    }
  }
  fclose(fp);
}

void similar_email(char email_input[])
{
  FILE* fp=fopen("data_base.txt","r");
  char single_contact[2000];
  char details[7][175], separate[6][50];
  int row, column, dashes, i, j, r, c;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    details[1][10]='\0';
    details[2][10]='\0';
    if(string_compare(details[3],email_input)==0)
    {
      print2D(details);
      break;
    }
  }
  fclose(fp);
}

int merge_phone(char phone_input[])
{
  char single_contact[2000], details[7][175];
  int i, j, row, column;
  FILE* fp=fopen("data_base.txt","r");
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    if(string_compare(phone_input,details[1])==0 || string_compare(phone_input,details[2])==0)
    {
      fclose(fp);
      return 1;
    }
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  return 0;
}

int merge_email(char email_input[])
{
  char single_contact[2000], details[7][175];
  int i, j, row, column;
  FILE* fp=fopen("data_base.txt","r");
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    if(string_compare(email_input,details[3])==0)
      return 1;
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  fclose(fp);
  return 0;
}

void add_remove_phone(char phone_input[])
{
  FILE* fp=fopen("data_base.txt","r");
  FILE* fpt=fopen("temp.txt","a+");
  char single_contact[2000], details[7][175];
  int i, j, row, column, count=0;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    if(count!=2 && (string_compare(details[1],phone_input)==0 || string_compare(details[2],phone_input)==0))
    {
      count++;
      fputs(single_contact,fpt);
      goto label;
    }
    else if(count!=2)
    {
      fputs(single_contact,fpt);
      goto label;
    }
    label: for(i=0;i<7;i++)
           {
             for(j=0;j<175;j++)
             details[i][j]='\0';
           }
  }
  remove("data_base.txt");
  rename("temp.txt","data_base.txt");
}


void add_remove_email(char email_input[])
{
  FILE* fp=fopen("data_base.txt","r");
  FILE* fpt=fopen("temp.txt","a+");
  char single_contact[2000], details[7][175];
  int i, j, row, column, count=0;
  while(fgets(single_contact,1999,fp))
  {
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    if(count!=2 && string_compare(details[3],email_input)==0)
    {
      count++;
      fputs(single_contact,fpt);
      goto label;
    }
    else if(count!=2)
    {
      fputs(single_contact,fpt);
      goto label;
    }
    label: for(i=0;i<7;i++)
           {
             for(j=0;j<175;j++)
             details[i][j]='\0';
           }
  }
  remove("data_base.txt");
  rename("temp.txt","data_base.txt");
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
    printf("\nEnter full name               : ");
    scanf("%s",info.name);
    fputs(info.name,fp);
    fprintf(fp,"\t");
    printf("Enter the 1st phone number      : ");
    scanf("%s",info.phone1);                
    if(merge_phone(info.phone1)==1)         
    {                                       
      printf("This telephone number already exists in the Directory.\n\n");
      printf("The following are the details of that contact: \n\n");
      similar_phone(info.phone1);
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
      add_remove_phone(info.phone1);
      goto label;
    }
    else
    {
      fputs(info.phone1,fp);
      fprintf(fp,"\t");
    }
    printf("Enter the 2nd phone number      : ");
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
    printf("Enter the email address         : ");
    scanf("%s",info.email);
    if(merge_email(info.email)==1 && info.email[0]!='-')
    {
      printf("This email already exists in thre directory.\n");
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
    printf("Enter the residential address   : ");
    scanf("%s",info.address);
    fputs(info.address,fp);
    fprintf(fp,"\t");
    printf("Enter the occupation : ");
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
  printf("✯✯✯✯✯ Data Accepted Successfully ✯✯✯✯✯\n");
  fclose(fp);
  return 0;
}
