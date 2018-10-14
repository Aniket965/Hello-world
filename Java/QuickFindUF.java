import java.util.*;
public class QuickFindUF
{
	private int id[];
	public QuickFindUF(int N)
	{
		id=new int[N];
	}
	public boolean connected(int p,int q)
	{
		return id[p]==id[q];
	}
	public void union(int p,int q)
	{
		int pid=id[p];
		int qid=id[q];
		for(int i=0;i<id.length;i++)
		{
			if(id[i]==pid)
			id[i]=qid;
		}
	}
}
