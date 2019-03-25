import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;


class MUL
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		BigInteger a,b,ans;
		while(n>0){
		    a = sc.nextBigInteger();
		    b = sc.nextBigInteger();
		    ans = a.multiply(b);
		    System.out.println(ans);
		    n=n-1;
		}
		
	}
}