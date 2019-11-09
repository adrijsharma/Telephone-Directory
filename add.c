#include<stdio.h>
#include<stdlib.h>
       struct Student
       {
	      char fname[50];
	      char lname[50];
              long int number;
       };

       int add()
       {
              FILE *fp;
	      char ch;
              struct Student Stu;

              fp = fopen("Student.dat","a");            //Statement   1

              if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");
                     exit(0);
              }

              do
              {
                      printf("\nFirst name : ");
                      scanf("%s",Stu.fname);

                      printf("Last name : ");
                      scanf("%s",Stu.lname);

                      printf("Enter Phone number : ");
                      scanf("%ld",&Stu.number);

                      fwrite(&Stu,sizeof(Stu),1,fp);


              }while(ch=='y' || ch=='Y');

              printf("\nData written successfully...");

              fclose(fp);
	      return 0;
       }
