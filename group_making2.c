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

int main(void)
{
  char group_name[100], group_name_check[100];
  int check=0;
  printf("Please enter a name for the new group you wish to create : ");
  scanf("%s",group_name);
  FILE* fp_group_names=fopen("group_names.txt","a+");
  while(fgets(group_name_check,100,fp_group_names))
  {
    if(string_compare(group_name_check,group_name)==0)
      check=1;
  }
  if(check==0)
  {
    int choice, index, i, j;
    char single_contact[2000], name[50];
    fprintf(fp_group_names,"%s\n",group_name);
    strcat(group_name,".txt");
    FILE* fp_group=fopen(group_name,"a+");
    FILE* fp=fopen("data_base.txt","a+");
    system("clear");
    printf("Names of people in your directory will appear one by one on the screen.\n");
    printf("Enter 1 if you want to add that particular person's contact details in the group, else enter any other number.\n\n"); 
    while(fgets(single_contact,1999,fp))
    {
      index=0;
      for(i=0;i<strlen(single_contact);i++)
      {
        if(single_contact[i]=='\t')
          break;
        else
        {
          name[index]=single_contact[i];
          index++;
        }
      }
      name[index]='\0';
      printf("%s : ",name);
      scanf("%d",&choice);
      printf("\n");
      if(choice==1)
        fprintf(fp_group,"%s",single_contact);
      for(i=0;i<index;i++)
        name[i]='\0';
    }
    printf("✯✯✯✯✯ Group Created Successfully ✯✯✯✯✯\n");
    fclose(fp);
    fclose(fp_group);
  }
  else
    printf("A group of this name already exists in the Directory.\n");
  fclose(fp_group_names);
  return 0;
}
