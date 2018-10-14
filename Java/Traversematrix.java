import java.util.Scanner;

public class Traversematrix{

public static void main(String args[]){

	Scanner scan = new Scanner(System.in);
	int value = scan.nextInt();
	boolean iseven = true;
	int a[][]= new int[10][10];		
	if(value%2==0)
	iseven=true;
	else
	iseven=false;
	int i,j;	

	int c=1;
	int l=1;
	int f=0;	

// suppose value =5
int temp=value;
while(temp>1)
{
	i=value-l;j=f;
	while(i>f)
	{	
		a[i][j]=c;			
		c++;
		i--;
	}
	while(j<value-l)
	{
		a[i][j]=c;	
		j++;
		c++;
	}
	while(i<value-l)
	{
		a[i][j]=c;
		i++;
		c++;
	}	
	while(j>f)
	{
		a[i][j]=c;
		c++;
		j--;
	}

f++;
l++;	
temp--;
}
if(iseven != true)	
a[value/2][value/2]=c;
	
// print the matrix
	for(i=0; i<value;i++)
	{
		for(j=0;j<value;j++)
		{
			System.out.print(a[i][j]+"\t");
		}
		System.out.println("");
	}


// End of main
}
// end of class
}
