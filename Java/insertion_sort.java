import java.util.*;
public class insertion {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=0;i<n;i++) {
			int temp=a[i];
			int j=i;
			while(j>0 && temp< a[j-1]) {
				a[j]=a[j-1];
				j-=1;
			}
			a[j]=temp;
		}
		for(int i=0;i<n;i++) {
			System.out.print(a[i]+" ");
		}
		sc.close();
	}
}
