#include<stdio.h>
#include<stdlib.h>
#include<string.h>
       struct Student
       {
              char fname[50];
	      char lname[50];
              long int number;
       };

       void view()
       {
              FILE *fp;
              char ch,search[50];
              struct Student Stu;

              fp = fopen("Student.dat","r");            //Statement   

              if(fp == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");
                     exit(0);
              }

	      printf("\nName\t\tNumber");
              while(fread(&Stu,sizeof(Stu),1,fp)>0)
	      {
		printf("\n%s %s\t%ld",Stu.fname,Stu.lname,Stu.number);
	      }
              fclose(fp);
       }
