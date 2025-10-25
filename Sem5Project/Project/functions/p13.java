//13. Write a Java method that checks whether all the characters in a given string are vowels (a, e,i,o,u) or not. Return true if each character in the string is a vowel, otherwise return false.
class Check
{
	boolean checkVowel(String s)
	{
		int x=0;
		int l=s.length();
		for(int i=0;i<l;i++)
		{
			if(s.charAt(i)=='a' || s.charAt(i)=='A' || s.charAt(i)=='e' || s.charAt(i)=='E' || s.charAt(i)=='i' || s.charAt(i)=='I' || s.charAt(i)=='o' || s.charAt(i)=='O' || s.charAt(i)=='u' || s.charAt(i)=='U')
			{
				x++;
			}
		}
		if(x==l)
		{
			return true;
		}
		return false;
	}
}

class Main
{
	public static void main(String st[]) throws java.io.IOException
	{
		String s;
		boolean res;
		
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
        java.io.BufferedReader br=new java.io.BufferedReader(isr);
				
		System.out.print("Enter a string : ");
		s=br.readLine();
		
		Check c=new Check();
		res=c.checkVowel(s);
		
		if(res==true)
		{
			System.out.println("String only contain vowels");
		}
		else
		{
			System.out.println("String doesn't only contain vowels");
		}
	}
}

/*

Output : 

Enter a string : aeiou
String only contain vowels

 */