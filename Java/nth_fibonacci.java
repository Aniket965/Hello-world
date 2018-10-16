class nth_fibonacci{
    public static void main(String args[]){    
        int a = 0,b = 1, c=a+b,i, n;    
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an integer");
        n = sc.nextInt();
        if(n==1)
            System.out.println("0");
        else if(n==2)
            System.out.println("1");
        else{
            for(i=2;i<n;++i){    
              c=a+b;   
              a=b;    
              b=c;    
            }
            System.out.println(c);
        } 
    }
}  
