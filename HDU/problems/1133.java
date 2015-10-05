import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main (String args[]) {
		Scanner in=new Scanner(System.in);
		int i,j;
		BigInteger dp[][]= new BigInteger[110][110];
		BigInteger fact[]=new BigInteger[110];
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				dp[i][j]=BigInteger.ZERO;
		dp[0][0]=BigInteger.ONE;
		for(i=1;i<=100;i++){
			dp[i][0]=BigInteger.ONE;
			for(j=1;j<=i;j++)
				dp[i][j]=dp[i-1][j].add(dp[i][j-1]);
		}
		fact[0]=BigInteger.ONE;
		for(i=1;i<=100;i++){
			fact[i]=fact[i-1].multiply(BigInteger.valueOf(i));
		}
		int n,m,t=0;
		while(in.hasNext()){
			n=in.nextInt();
			m=in.nextInt();
			if(n==0&&m==0) return;
			System.out.println("Test #"+ ++t +":");
			System.out.println(dp[n][m].multiply(fact[m].multiply(fact[n])));
		}
	}
}
