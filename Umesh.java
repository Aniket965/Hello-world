import java.util.*;
import java.io.*;
import java.math.*;
class Solution{
    static int a[][];
    static long dp[][];
    static int n;
    public static void main(String[] args)throws Exception{
        int t=nextInt();
        while(t-->0){
            n=nextInt();
            int k=nextInt();
            a=new int[n][];
            dp=new long[n][k+1];
            for(int i=0;i<n;i++){
                int m=nextInt();
                a[i]=new int[m];
                for(int j=0;j<m;j++)
                    a[i][j]=nextInt();
            }
            long ans=solve(0,k);
            System.out.println(ans);
        }
    }
    static long solve(int i,int k){
        if(i<n && dp[i][k]!=0)
            return dp[i][k];
        if(i==n-1){
            dp[i][k]=getMaxSum(i,k);
            return dp[i][k];
        }
        long ans=0;
        int l=Math.min(k,a[i].length);
        for(int j=0;j<=l;j++)
            ans=Math.max(getMaxSum(i,j)+solve(i+1,k-j),ans);
        dp[i][k]=ans;
        return ans;
    }
    static long getMaxSum(int i,int k){
        long sum=0;
        long max=0;
        if(a[i].length<k)
            return Long.MIN_VALUE;
        for(int j=0;j<k;j++)
            sum=sum+a[i][j];
        max=sum;
        if(k==a[i].length)
            return max;
        int last=a[i].length-1;
        for(int j=k-1;j>=0;j--,last--){
            sum=sum-a[i][j]+a[i][last];
            max=Math.max(sum,max);
        }
        return max;
    }
    static int nextInt()throws IOException{
        InputStream in=System.in;
        int ans=0;
        boolean flag=true;
        byte b=0;
        boolean neg=false;
        while ((b>47 && b<58) || flag){
            if(b==45)
                neg=true;
            if(b>=48 && b<58){
                ans=ans*10+(b-48);
                flag=false;
            }
            b=(byte)in.read();
        }
        if(neg)
            return -ans;
        return ans;
    }
 
    static long nextLong()throws IOException{
        InputStream in=System.in;
        long ans=0;
        boolean flag=true;
        byte b=0;
        while ((b>47 && b<58) || flag){
            if(b>=48 && b<58){
                ans=ans*10+(b-48);
                flag=false;
            }
            b=(byte)in.read();
        }
        return ans;
    }
    static String next()throws Exception{
        StringBuilder sb=new StringBuilder(1<<16);
        InputStream in=System.in;
        byte b=0;
        do{
            if(!isWhiteSpace(b))
                sb.append((char)b);
            b=(byte)in.read();
        }while(!isWhiteSpace(b) || sb.length()==0);
        return sb.toString();
    }
    static boolean isWhiteSpace(byte b){
        char ch=(char)b;
        return ch=='\0' || ch==' ' || ch=='\n';
    }
} 
