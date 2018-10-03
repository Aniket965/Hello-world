import java.util.Scanner;

public class HollowDiamondPattern {
	public static void hollowDiamond(int n){
	      int ts,space,row=1,col=1;
	      
	      while(row<=n)
	      {
	        ts=n-row;
	        for(space=1;space<=ts;space++)
	        {
	          System.out.print(" ");
	        }
	 
	        int val=row-1;
	        System.out.print('*');
	        for(int i=1;i<=2*val-1;i++)
	          System.out.print(' ');
	        
	        if(val!=0)
	          System.out.print('*');
	        
	        System.out.println();
	        
	        row++;
	      }
	      
	      row=n-1;
	      int k=0;
	      int j=0;
	      while(row>0)
	      {
	        k++;
	        for(j=0;j<k;j++)
	          System.out.print(' ');
	        
	        System.out.print('*');
	        
	        int val1=row-1;
	        for(j=1;j<=2*val1-1;j++)
	          System.out.print(' ');
	        
	        if(val1!=0)
	          System.out.print('*');
	        
	        System.out.println();
	        row--;
	      }
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		hollowDiamond(n);


	}
	
}


