//7. Write a Java method to check whether a string is a valid password.
class Check
{
	String checkPass(String s)
	{
		int len=s.length(),upper=0,lower=0,digit=0,special=0;
		if(len<8)
		{
			return "Not a valid password";
		}
		else
		{
			for(int i=0;i<len;i++)
			{	
				if(s.charAt(i)>='A' && s.charAt(i)<='Z')
				{
					upper++;
				}
				else if(s.charAt(i)>='a' && s.charAt(i)<='z')
				{
					lower++;
				}
				else if(s.charAt(i)>='0' && s.charAt(i)<='9')
				{
					digit++;
				}
				else
				{
					special++;
				}
			}
			
			if(upper>=1 && lower>=1 && digit>=1 && special>=1)
			{
				return "A valid password";
			}
			else
			{
				return "Not a valid password";
			}
		}
	}
}

class Main
{
	public static void main(String s[]) throws java.io.IOException
	{
		String a;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		System.out.println("A password should have : \n1. atleast 8 character \n2. atleast 1 uppercase \n3. atleast 1 lowercase \n4. atleast 1 digit \n5. atleast 1 special character");
		System.out.print("Enter the password : ");
		a=br.readLine();
		
		Check c=new Check();
		System.out.println(c.checkPass(a));
	}
}


/*
 
Output : 

A password should have :
1. atleast 8 character
2. atleast 1 uppercase
3. atleast 1 lowercase
4. atleast 1 digit
5. atleast 1 special character
Enter the password : Abcd@123
A valid password

 */