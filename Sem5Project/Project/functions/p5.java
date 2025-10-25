//5. Write a Java method to compute the future investment value at a given interest rate for a specified number of years.
class Interest
{
	double simpleInterest(int p,int r,int t)
	{
		return (p*r*t)/100;
	}
}

class Main
{
	public static void main(String s[])
	{
		String a;
		int p,r,t;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter the principle amount : ");
			a=br.readLine();
			p=Integer.parseInt(a);
			
			System.out.print("Enter the rate of interest : ");
			a=br.readLine();
			r=Integer.parseInt(a);
			
			System.out.print("Enter the time period : ");
			a=br.readLine();
			t=Integer.parseInt(a);
			
			Interest i=new Interest();
			
			System.out.println("Total interest : "+i.simpleInterest(p,r,t));
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
	}
}

/*
 
Output : 

Enter the principle amount : 1000
Enter the rate of interest : 7
Enter the time period : 2
Total interest : 140.0

 */