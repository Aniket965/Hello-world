int main ()
{
  int n, j;
  printf("Enter n : ");
  scanf ("%d", &n);
  
  for(int i=1; i<=n; i++)
    {
      for(j=1; j<=(n+1-i); j++)
	    printf ("%c",'A'+j-1);
	    
      for(int k=1; k<=(2*i-3); k++)
    	{
    	    if (i != 1)
    	      printf (" ");
    	}
    	
       if(i == 1)
	       j -= 1;	
	       
      for(; j>1; j--)
	    {
	        printf ("%c",'A'+j-1-1);
	    }
        printf ("\n");
    }
printf("Thank you bro");
}