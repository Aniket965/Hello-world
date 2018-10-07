
public class KadanesAlgorithm {
	//Max subarray sum!!
	//Print sequence too
public static void main(String args[]) {
	
	int[] arr = {5,7,-14,2,3,9,-4,6,-18,7};
	
	int cmax = arr[0];
	int omax = arr[0];
	
	int cs = 0;
	int ce=0;
	int os=0;
	int oe=0;
	
	for( int i=1; i<arr.length; i++) {
		if(cmax >= 0 ) {
			cmax += arr[i];
			ce++;
		}
		else {
			cs = i; ce=i;
			cmax = arr[i];
		}
		
		if(cmax>omax) {
			os = cs;
			oe = ce;
			omax = cmax;
		}
	}
	
	System.out.println("Index from " +os +" to "+ oe);
	System.out.println("Max subarray sum : "+omax);
	
}

}
