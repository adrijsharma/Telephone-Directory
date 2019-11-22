#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

int partial_compare(char small[100], char large[100])
{
  int compare, count, check=0, index=0, i, j, k, s=strlen(small), l=strlen(large), array[100];
  if(s<=l)
  {
    for(i=0;i<l;i++)
    {
      if(small[0]==large[i] || abs((int)small[0]-(int)large[i])==32)
      {
        array[index]=i;
        index++;
      } 
    }
    for(i=0;i<index;i++)
    {
      count=0;
      for(j=array[i],k=0; j<array[i]+s; j++,k++)
      {
        if(large[j]==small[k] || abs((int)small[k]-(int)large[j])==32)
        count++;
      }
      if(count==s)
      {
        check=1;
        compare=0;
        break;
      }
    }
    if(check==0)
      compare=1;
  }
  else
    compare=1;
  return compare;
}

int main(void)
{
  FILE* fp=fopen("data_base.txt","a+");
  char single_contact[2000], search_material[50];
  char details[7][175];
  int search_choice, row, column, i, j, check=0;
  printf("Please select the appropriate option to search through in the Directory\n");
  printf("Enter\n");
  printf("1 for searching through NAME\n");
  printf("2 for searching through PHONE NUMBER\n");
  printf("3 for searching through EMAIL ADDRESS\n");
  printf("4 for searching through OCCUPATION\n");
  printf("5 for searching through DATE OF BIRTH\n");
  scanf("%d",&search_choice);
  system("clear");
  switch(search_choice)
  {
    case 1: printf("Please enter the name to be searched in the directory\n");
            scanf("%s",search_material);
            search_material[strlen(search_material)]='\0';
            break;
  
    case 2: printf("Please enter the phone number to be searched in the directory\n");
            scanf("%s",search_material); 
            search_material[10]='\0';
            break;

    case 3: printf("Please enter the email address to be searched in the directory\n");
            scanf("%s",search_material);
            break;
    
    case 4: printf("Please enter the occupation to be searched in the directory\n");
            scanf("%s",search_material);
            break;

    case 5: printf("Please enter the date of birth in dd/mm/yyyy format to be searched in the directory\n");
            scanf("%s",search_material);
            break;
    
    default: printf("You are requested to make a valid input choice");
             break;
  }
  system("clear");
  printf("Search Results are as follows: \n\n");
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
    switch(search_choice)
    {
      case 1: details[0][strlen(details[0])]='\0';
              details[1][10]='\0';
              if(partial_compare(search_material,details[0])==0)
              {
                print2D(details);
                check=1;
              }
              break;
 
      case 2: details[1][10]='\0';
              if(partial_compare(search_material,details[1])==0 || partial_compare(search_material,details[2])==0)
              {
                print2D(details);
                check=1;
              }
              break;
 
      case 3: if(partial_compare(search_material,details[3])==0)
              {
                print2D(details);
                check=1; 
              }
              break;
 
      case 4: if(partial_compare(search_material,details[5])==0)
              {
                print2D(details);
                check=1; 
              }
              break;

      case 5: details[6][10]='\0';
              if(partial_compare(search_material,details[6])==0)
              {
                print2D(details);
                check=1; 
              }
              break;
    }
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  if(check==0 && (search_choice==1 || search_choice==2 || search_choice==3 || search_choice==4 || search_choice==5))
    printf("NO Match found\n");
  fclose(fp);
}  
