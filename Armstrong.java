import java.io.*;
import java.util.*;

class Calculate
{
   public int Cube (int n)
    {
       int p=math.pow (n,3);//calculating cube using the pow()
         return p;
    }
 
  public static void main (String args[])
    { 
       int n,m,r,sum=0;
       Scanner sc= new Scanner(System.in);
       System.out.println("Enter the number to be checked:");
       n=sc.nextInt();//getting an input from the user
       Calculate ob=new Calculate();//creating an object of class Calculate
       m=n;

       while (m!=0)
       {
          r=m%10;//extracting a digit from the number entered
          sum+= ob.Cube(r);//calculating the sum of cube of digits by calling Cube()
          m/=10;
       }
         
       if(sum==n) //Checking whether the sum of cube of digits is equal to the number entered
        System.out.println(n+" is an armstrong number");
       else
        System.out.println(n+" is not an armstrong number");
     
    }//end of main()
} //End of Calculate
