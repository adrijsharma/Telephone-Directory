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
  //View function.
  int search_choice, i, number_of_contacts, index=0, search_array[100];
  printf("Please select the appropriate option to search through in the directory\n");
  printf("Enter\n");
  printf("1 for searching through NAME\n");
  printf("2 for searching through PHONE NUMBER\n");
  printf("3 for searching through EMAIL ADDRESS\n");
  printf("4 for searching through OCCUPATION\n");
  printf("5 for searching through DATE OF BIRTH\n");
  scanf("%d",&search_choice);
  struct Contact_Details contacts[number_of_contacts];
  switch(search_choice)
  {
    case 1: printf("Please enter the name to be searched in the directory\n");
            char search_name[50];
            scanf("%s",search_name);
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].name,search_name)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            break;
 
    case 2: printf("Please enter the phone number to be searched in the directory\n");
            char search_phone[50];
            scanf("%s",search_phone);
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].phone_number1,search_phone)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].phone_number2,search_phone)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            break;
 
    case 3: printf("Please enter the email address to be searched in the directory\n");
            char search_email[50];
            scanf("%s",search_email);
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].email_address,search_email)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            break;
 
    case 4: printf("Please enter the occupation to be searched in the directory\n");
            char search_occupation[50];
            scanf("%s",search_occupation);
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].occupation,search_occupation)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            break;

    case 5: printf("Please enter the date of birth in dd/mm/yyyy format to be searched in the directory\n");
            char search_dob[50];
            scanf("%s",search_dob);
            for(i=0;i<number_of_contacts;i++)
            {
              if(strcmp(contacts[i].date_of_birth,search_dob)==0)
              {
                search_array[index]=i;
                index++;
              }
            }
            break;
   
    default: printf("You are requested to make a valid input choice");
             break;
  }
  if(index>0)
  {
    if(index>1)
      printf("%d matches were found\n",index);
    else if(index==1)
      printf("Only 1 match found");   
    printf("The following are the details:\n");
    for(i=0;i<index;i++)
    {
      printf("Name: %s\n",contacts[search_array[i]].name);
      printf("Phone Number: %s\n",contacts[search_array[i]].phone_number1);
      if(contacts[search_array[i]].phone_number2[0]!='*')
        printf("              %s\n",contacts[search_array[i]].phone_number2);
      if(contacts[search_array[i]].email_address[0]!='*')
        printf("Email Address: %s",contacts[search_array[i]].email_address);
      if(contacts[search_array[i]].residential_address[0]!='*')
        printf("Residential Address: %s",contacts[search_array[i]].residential_address);
      if(contacts[search_array[i]].occupation[0]!='*')
        printf("Occupation: %s",contacts[search_array[i]].occupation);
      if(contacts[search_array[i]].date_of_birth[0]!='*')  
        printf("Date of Birth: %s",contacts[search_array[i]].date_of_birth);
    }
  }
  else if(index==0)
    printf("NO Match found");
  return 0;
}
              
