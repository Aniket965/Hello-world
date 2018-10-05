class prime
{
    void main()
    {
     Scanner sc=new Scanner(System.in);
        int n;
int c=0;
System.out.println("Enter the no.");
n=sc.nextInt();
for(int i=2;i<=n;i++)
{
if(n%i==0)
c++;
}
if(c==1)
System.pout.println("Prime");
else
System.out.println("Not prime");
}
}
