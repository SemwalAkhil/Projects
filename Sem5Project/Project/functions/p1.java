//1. Write a Java method to find the smallest number among three numbers.
class Smallest
{
	int smallNumber(int x,int y,int z)
	{
		if(x<y && x<z)
			return x;
		else if(y<x && y<z)
			return y;
		else if(z<x && z<y)
			return z;
		else
			return x;
	}
}

class Main
{
	public static void main(String st[])
	{
		String a,b,c;
		int x,y,z,ans=0;
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
			
			Smallest s=new Smallest();
			ans=s.smallNumber(x,y,z);
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		
		System.out.println("Smallest number is : "+ans);
	}
}


/*
 
Output : 

Enter first number : 10
Enter second number : -10
Enter third number : 20
Smallest number is : -10

 */