#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

int serial_number=1;

void print2D(char array2d[7][175], int s_no)
{
  printf("Contact Number #%d\n",s_no);
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

int main(void)
{
  char group_name[30], single_contact[2000], details[7][175], group_name_check[100];
  int i, j, row, column, serial_number=1;
  printf("Please enter a name of the already created group you wish to view: ");
  scanf("%s",group_name);
  printf("Following are the details of the Group %s: \n\n",group_name);
  strcat(group_name,".txt");
  FILE* fp_group=fopen(group_name,"r");
  while(fgets(single_contact,1999,fp_group))
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
    print2D(details,serial_number);
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
    serial_number++;
  }
  fclose(fp_group);
}
