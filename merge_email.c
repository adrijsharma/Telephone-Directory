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
