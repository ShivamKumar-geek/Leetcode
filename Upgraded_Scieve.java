/* Upgraded Scieve with O(n) Complexity*/


import java.util.*;
import java.io.*;
import java.lang.*;

public class Scieve
{
	static int n=0;
	static ArrayList<Integer> prime= new ArrayList<Integer>();
	static ArrayList<Boolean> isprime= new ArrayList<Boolean>(n+1);
	static ArrayList<Integer> spf= new ArrayList<Integer>(n+1);
	public static void scieve()
	{
		
		int i=0,j=0;
		for(i=0;i<=n;i++){
			isprime.add(true);
			spf.add(0);
		}
		isprime.set(0,false);
		isprime.set(1,false);
		
		for(i=2;i<=n;i++)
		{
			if(isprime.get(i))
			{
				
				prime.add(i);
				spf.set(i,i);
			}
		
			for(j=0;j<prime.size() && i*prime.get(j)<=n && prime.get(j)<=spf.get(i);j++)
			{
				isprime.set(i*prime.get(j),false);
				spf.set((i*prime.get(j)),prime.get(j));
			}
		}
		
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		scieve();
		System.out.println();
		for( int m : prime)
			System.out.print(m+" ");
	}
}

		