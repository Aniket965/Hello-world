class factorial
{
  void main()
  {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int f=1;
    for (int i=2;i<=n;i++)
    { 
        f=f*i;
    }
    System.out.println(f);
  }
}
    
