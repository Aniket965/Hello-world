package kik;
public class May {
	public static void main(String[] args) {
		int []arrayku = {2,4,5,21,4,6,1,88};
		int i,j,k,psskecil,numkecil;
		for(i=0 ; i < arrayku.length ; i++) {
			numkecil = arrayku[i];
			psskecil = i;	
			for(j=i ; j<arrayku.length ; j++) {
				if(arrayku[j] < numkecil) {
					numkecil = arrayku[j];
					psskecil = j;
				}
			}
			int gelasC;
			gelasC = arrayku[i];
			arrayku[i] = arrayku[psskecil];
			arrayku[psskecil] = gelasC;
		}
		for(k=0 ; k<arrayku.length ; k++) {
			System.out.print(" "+arrayku[k]);
		}	
	}
}