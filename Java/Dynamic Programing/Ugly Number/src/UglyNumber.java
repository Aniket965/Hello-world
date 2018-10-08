
public class UglyNumber {

	public UglyNumber() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int ugly[] = new int[150];
		
		int i2 = 0, i3 = 0, i5 = 0;
		
		int next_ugly, next_ugly2 , next_ugly3 , next_ugly5;
		
		ugly[0] = 1;
		System.out.println(ugly[0]);
		for(int i = 1 ; i < 150 ; i++)
		{
			next_ugly2 = ugly[i2] * 2; 
			next_ugly3 = ugly[i3] * 3; 
			next_ugly5 = ugly[i5] * 5;
			
			ugly[i] = min(next_ugly2 , next_ugly3 , next_ugly5);
			next_ugly = ugly[i];
			
			if(next_ugly == next_ugly2)
			{
				i2 = i2 + 1;
			}
			if(next_ugly == next_ugly3)
			{
				i3 = i3 + 1;
			}
			if(next_ugly == next_ugly5)
			{
				i5 = i5 + 1;
			}
			System.out.println(ugly[i]);
		}
	}

	private static int min(int next_ugly2, int next_ugly3, int next_ugly5) {	
		return ((next_ugly2 < next_ugly3) ? (next_ugly2 < next_ugly5) ? next_ugly2 : next_ugly5 : (next_ugly3 < next_ugly5) ? next_ugly3 : next_ugly5) ;
	}

}
