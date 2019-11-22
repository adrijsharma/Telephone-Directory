
void add_remove(char phone_input[])
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
