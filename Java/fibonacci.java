package day4;

javax.swing.JOptionPane;


public class Fibonacci {

	public static void main(String[] args) {
		
		int n = Integer.parseInt(JOptionPane.showInputDialog("Enter number of terms :"));
		String serie = "";
		
		int[] fibonacci = new int[n];
		
		fibonacci[0] = 1;
		
		fibonacci[1] = 1;
		
		for(int i=2;i<n;i++)
		{
			fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
			
		}
		for(int j=0;j<n;j++){
                   if(j == n-1){
			 serie += (fibonacci[j]);
                   }else{
                       serie += (fibonacci[j] + " , ");
                   }
		}
                JOptionPane.showMessageDialog(null , "The series is: \n" + serie);
		
	}

}
