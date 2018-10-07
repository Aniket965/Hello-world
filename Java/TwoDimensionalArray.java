

public class TwoDimensionalArray {

	public static void main(String[] args) {

		int[][] TwoDim = new int[3][3]; 
		
		TwoDim[2][2] = 9;
		
    //prints values of the 2D array
    
  
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(TwoDim[i][j]); // print prints on same line
			}
            System.out.println("");		// goes to next line 	

			 
		}
	}

}
