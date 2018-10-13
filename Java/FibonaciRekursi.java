package kik;
public class FibonaciRekursi {
	public static int fib(int x){
        if (x<=0 || x<=1){
            return x;
        }
        else{
            return fib(x-2)+fib(x-1);
        }
    }
    public static void main(String[]args){
        int n=10;
        for (int i=0;i<n;i++){
            System.out.print(fib(i)+" ");
        }
    }
}