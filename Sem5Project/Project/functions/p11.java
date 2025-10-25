//11. Write a Java method that accepts three integers and checks whether they are consecutive or not. Returns true or false.
class Check
{
	boolean consecutive(int x,int y,int z)
	{
		if(x+1==y)
		{
			if(y+1==z)
			{
				return true;
			}
			return false;
		}
		return false;
	}
}

class Main
{
	public static void main(String st[]) throws java.io.IOException
	{
		String s;
		int x,y,z;
		boolean res;
		
		Check c=new Check();
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter first number : ");
			s=br.readLine();
			x=Integer.parseInt(s);
			
			System.out.print("Enter second number : ");
			s=br.readLine();
			y=Integer.parseInt(s);
			
			System.out.print("Enter third number : ");
			s=br.readLine();
			z=Integer.parseInt(s);
			
			res=c.consecutive(x,y,z);
			
			if(res==true)
			{
				System.out.println("Numbers are consecutive");
			}
			else
			{
				System.out.println("Number are not consecutive");
			}
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}


/*

Output : 

Enter first number : 4
Enter second number : 5
Enter third number : 6
Numbers are consecutive

 */