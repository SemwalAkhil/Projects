//2. Write a Java method to compute the average of three numbers.
class Average
{
	float averageNumber(int x,int y,int z)
	{
		return (x+y+z)/3.00f;
	}
}

class Main
{
	public static void main(String st[])
	{
		String a,b,c;
		int x,y,z;
		float ans=0;
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter first number : ");
			a=br.readLine();
			x=Integer.parseInt(a);
			
			System.out.print("Enter second number : ");
			b=br.readLine();
			y=Integer.parseInt(b);
			
			System.out.print("Enter third number : ");
			c=br.readLine();
			z=Integer.parseInt(c);
			
			Average avg=new Average();
			ans=avg.averageNumber(x,y,z);
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		
		System.out.println("Average of 3 numbers : "+ans);
	}
}


/*
 
Output : 

Enter first number : 10
Enter second number : 15
Enter third number : 10
Average of 3 numbers : 11.666667

 */