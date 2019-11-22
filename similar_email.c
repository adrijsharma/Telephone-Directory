void print2D(char array2d[7][175])
{
  array2d[0][strlen(array2d[0])]='\0';
  array2d[1][10]='\0';
  //printf("\n");
  printf("Name                : %s",array2d[0]);
  printf("\nPhone Number        : %s",array2d[1]);
  if(array2d[2][0]!='-')
  {
    array2d[2][10]='\0';
    printf("\n                      %s",array2d[2]);
  }
  if(array2d[3][0]!='-')
    printf("\nEmail Address       : %s",array2d[3]);
  if(array2d[4][0]!='-')
    printf("\nResidential Address : %s",array2d[4]);
  if(array2d[5][0]!='-')
    printf("\nOccupation          : %s",array2d[5]);
  if(array2d[6][0]!='-')
  {
    array2d[6][10]='\0';
    printf("\nDate of Birth       : %s",array2d[6]);
  }
  printf("\n\n");
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

