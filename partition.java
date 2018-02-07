import java.util.*;
class partition{
	public static void main(String c[]){
		Scanner sc=new Scanner(System.in);
		long n,x,sum,t,temp;
		t=sc.nextLong();
		while(t-->0){
			x=sc.nextLong();
			n=sc.nextLong();
			if(n<=3){
				System.out.println("impossible");
			}
			else{
				sum=(n*(n+1))/2;
				sum=sum-x;
				if(sum%2==1)
					System.out.println("impossible");
				else{
					sum=sum/2;
					HashSet<Long> arr = new HashSet<Long>();
					temp=n;
					while(sum>0 && temp>0){
						if(temp==x)
							temp--;
						else{
							if(sum-temp>=0 && sum-temp!=x ){
								arr.add(temp);
								sum=sum-temp;
							}
							temp--;
						}
						
					}
					if(sum>0)
						System.out.println("impossible");
					else{
						for(long i=1;i<=n;i++){
							if(i==x)
								System.out.print("2");
							else if(arr.contains(i))
								System.out.print("1");
							else
								System.out.print("0");
						}
						System.out.println("");
					}
				}
			}
		}


	}
}