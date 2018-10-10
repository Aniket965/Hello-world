public class QuickUnionUF
{
	private int[] id;
	
	public QuickUnionUF(int n)
	{
		id = new int[N];
		for(int i=0;i<n;i++)
		{
			id[i]=i;
		}
	}
	
	private int root(int i)
	{
		while(i != id[i])
		{
			i=id[i];
		}
		return i;
	}
	
	public boolean connected(int p,int q)
	{
		return root(p)==root(q);
	}
	
	public void union(int p,int q)
	{
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}
}