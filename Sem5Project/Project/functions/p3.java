//3. Write a Java method to display the middle character of a string.
class Middle
{
	char middleChar(String s,int l)
	{
		char c=' ';
		for(int i=0;i<l;i++)
		{
			c=s.charAt(i);
		}
		return c;
	}
}

class Main
{
	public static void main(String st[])
	{
		String a;
		int c,len;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		try
		{
			System.out.print("Enter a string : ");
			a=br.readLine();
			
			len=a.length();
			
			Middle m=new Middle();
			
			if(len%2==0)
			{
				System.out.println("String has even length");
				c=len/2;
				System.out.println("Middle character of string is : "+m.middleChar(a,c));
			}
			else
			{
				System.out.println("String has odd length");
				c=len/2;
				System.out.println("First Middle character of string is : "+m.middleChar(a,c));
				System.out.println("Second Middle character of string is : "+m.middleChar(a,c+1));
			}
		}
		catch(java.io.IOException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}


/*
 
Output : 

Enter a string : abcd
String has even length
Middle character of string is : b

 */