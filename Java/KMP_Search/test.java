
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class test
{
	static class FastReader
	{
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader()
		{
			br =new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next()
		{
			while (st==null || (!st.hasMoreElements())) 
			{
				try
				{
					st =new StringTokenizer(br.readLine());
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
				
			}
			return st.nextToken();
		}
 
		int nextInt()
		{
			return Integer.parseInt(next());
		}
	}//END OF USER-DEFINED CLASS FOR FAST INPUT
 
	static int N ;
 
 /*KMP Search function implements the concept of searching a pattern string in the given String with O(N) time-complexity .The given
 function just searches for the first occurence of the given 'pat' Pattern string in the given 'str' String , as soon as we get the 
 first occurence ,it raises the flag and breaks the process .If the pattern does not occur in the given string ,then the flag is not
 raised and the process terminates in its usual way .*/
 
	public static boolean KMP_search(String[] pat , String[] str)
	{
		String[] arr =new String[ ((3*N)/2) + 1 ];	
 
		int i ,j ,k ;	j =0;k =0;	boolean res =false;
 
		for(i =0;i<arr.length;i++)
		{
			if(i<(N/2))
				arr[i] =pat[j++];
			else
			{
				if(i == (N/2))
					arr[i] ="#";
				else
					arr[i] =str[k++];
			}
		}
 
		int[] F =new int[ ((3*N)/2) + 1 ];
 
		F[0] =0;
 
		for(i =1;i<arr.length;i++)
		{
			j =F[i - 1];
 
			while((j>0) && (arr[i].equals(arr[j]) == false))
				j =F[j - 1];
 
			if(arr[i].equals(arr[j]) == true)
				F[i] =j + 1;
			else
				F[i] =j;
 
			if(F[i] == (N/2)){
				res =true;	break;
			}
		}
		return res;
	}//END OF KMP_SEARCH FUNCTION
 
	public static void main(String[] args)
	{
		FastReader fr =new FastReader(); //Object of Fast Input Class
 
		PrintWriter op =new PrintWriter(System.out); //Object of Fast Output Class
 
		int T =fr.nextInt(); //Number of test-cases
 
		int i ,j ,k ; //Temporary variables
 
		String[] evA ,odA ,evB ,odB ; //Even and Odd parts of Equal Length Strings A and B
 
		while(T-- > 0)
		{
			N =fr.nextInt(); //Length of Strings A and B
  
			evA =new String[ N/2 ];	odA =new String[ N/2 ];	j =0;k =0;
 
			for(i =0;i<N;i++)
			{
				if((i%2) == 0)
					evA[j++] =fr.next();
				else
					odA[k++] =fr.next();
			}// Storing the even and odd parts of String A
 
      /*Here ,permutations of even and odd parts of the String A are to be searched in the even and odd parts of the String B as a 
      pattern ,thus even and odd parts of the String B are stored as appended versions of themselves ; Forr instance : 
      if A = BCAD , B =ADBC ,odd(A) =BA ,even(A) =CD ,odd(B) =AB ,even(B) =DC , then we can see that in ABAB ,clearly BA is there ...
      Similarly in DCDC ,clearly CD is there as a substring ... */
      
			evB =new String[N];	odB =new String[N];	j =0;k =0;
 
			for(i =0;i<N;i++)
			{
				if((i%2) == 0){
					evB[j] =fr.next();	evB[j + (N/2)] =evB[j];	j++;
				}
				else{
					odB[k] =fr.next();	odB[k + (N/2)] =odB[k];	k++;
				}
			}// Storing the appended versions of even and odd parts of the String B 
 
			if(KMP_search(evA , evB) == true)
			{
				if(KMP_search(odA , odB) == true)
					op.println("Yes");
				else
					op.println("No");				
			}// Checking whether permutation of even(A) and odd(A) respectively are present in even(B) and odd(B) 
			else
			{
				if(KMP_search(evA , odB) == true)
				{
					if(KMP_search(odA , evB) == true)
						op.println("Yes");
					else
						op.println("No");
				}
				else
					op.println("No");
			}// Checking whether permutation of even(A) and odd(A) respectively are present in odd(B) and even(B)
		}
		op.flush();	op.close(); //Flushing and closing of O/P stream
	}// END OF MAIN FUNCTION
}// END OF test CLASS
