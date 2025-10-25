//9. Write a Java method to find all twin prime numbers less than 100.
class Prime
{
	int isPrime(int x)
	{
		for(int j=2;j<=x/2;j++)
		{
			if(x%j==0)
			{
				return 0;
			}
		}
		return x;
	}
	void twinPrime()
	{
		for(int i=2;i<=100;i++)
		{
			if(isPrime(i)!=0)
			{
				if(isPrime(i+2)!=0)
				{
					System.out.println("("+i+" , "+(i+2)+")");
				}
			}
		}
	}
}

class Main
{
	public static void main(String st[])
	{
		Prime p=new Prime();
		System.out.println("All twin prime number between 1 to 100 : ");
		p.twinPrime();
	}
}


/*

Output : 

All twin prime number between 1 to 100 :
(3 , 5)
(5 , 7)
(11 , 13)
(17 , 19)
(29 , 31)
(41 , 43)
(59 , 61)
(71 , 73)

 */