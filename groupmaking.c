#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact_Details
{
  char name[50];
  char phone_number1[11];
  char phone_number2[11];
  char email_address[40];
  char residential_address[175];
  char occupation[175];
  char date_of_birth[11];
};

int main(void)
{
  char group_name[30];
  printf("Please enter a name for your group\n");
  scanf("%s",group_name);
  strcat(group_name,".txt");
  FILE* fp_group=fopen(group_name,"a");
  int number_of_contacts, i, serial_numbers[100];
  struct Contact_Details contacts[number_of_contacts];
  printf("From the below given list of people, \n");
  printf("Type, with spaces, the corresponding serial number associated with the name you wish to add.\n");
  printf("When you are finished writing the serial numbers, type 0 after a space and press ENTER key.");
  int index=0;
  while(index==0 || serial_numbers[index-1]!=0)
  {
    scanf("%d",&serial_numbers[index]);
    index++;
  }
  for(i=0;i<index;i++)
  {
    if(contacts[serial_numbers[i]-1].phone_number2[0]=='*')
      fprintf(fp_group,"%s\t%s\n",contacts[serial_numbers[i]-1].name,contacts[serial_numbers[i]-1].phone_number1);
    else if(contacts[serial_numbers[i]].phone_number2[0]!='*')
    {
      fprintf(fp_group,"%s\t%s\t",contacts[serial_numbers[i]].name,contacts[serial_numbers[i]].phone_number1);
      fprintf(fp_group,"%s\n",contacts[serial_numbers[i]].phone_number2);
    }
  }
  return 0;
}
    
 
