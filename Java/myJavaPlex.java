class fib{
  static int fibo(int num){
    int[] fibA = new int[num+2];
    
    fibA[0] = 0;
    fibA[1] = 1;
    
    for (int i=2; i<=n ;i++){
      fibA[i] = fibA[i-1] + fibA[i-2];
    }
    return fibA[num];
  }
  
  public static void main(String args[]){
    System.out.println(fibo(15));
  }
  
}
