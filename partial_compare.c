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

