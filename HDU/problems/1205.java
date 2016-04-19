import java.util.*;

public class Main {
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int t=in.nextInt();
		while(t-->0){
			int n=in.nextInt();
			long sum=0,mx=0,tmp;
			for(int i=1;i<=n;i++){
				tmp=in.nextLong();
				sum+=tmp;
				if(mx<tmp) mx=tmp;

			}
			if((sum+1)/2>=mx) System.out.println("Yes");
			else System.out.println("No");

		}

	}

}
