//5. Program to determine whether two matrices are equal
class Matrices
{
	int mat[][];
	int r;
	int c;
	
	java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
	java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
	Matrices(int r,int c)
	{
		this.r=r;
		this.c=c;
		mat=new int[r][c];
	}
	
	void addData() throws NumberFormatException,java.io.IOException
	{
		String s;
		System.out.println("Enter data of matrix : ");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print("Enter value at index ("+(i+1)+","+(j+1)+") : ");
				s=br.readLine();
				mat[i][j]=Integer.parseInt(s);
			}
		}
	}
	void displayMatrix()
	{
		System.out.println("Data in matrix :");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print(mat[i][j]+"	");
			}
			System.out.println();
		}
	}
	int equalMatrix(Matrices m)
	{
		if(this.r==m.r && this.c==m.c)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(this.mat[i][j]!=m.mat[i][j])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
class Main
{
	public static void main(String st[]) throws NumberFormatException,java.io.IOException
	{
		java.io.InputStreamReader isr=new java.io.InputStreamReader(System.in);
		java.io.BufferedReader br=new java.io.BufferedReader(isr);
		
		int r,c;
		String s;
		
		System.out.println("Enter data of first matrix : ");
		System.out.print("Enter the number of rows : ");
		s=br.readLine();
		r=Integer.parseInt(s);
		System.out.print("Enter the number of columns : ");
		s=br.readLine();
		c=Integer.parseInt(s);
			
		Matrices m1=new Matrices(r,c);
		
		System.out.println();
		m1.addData();
		System.out.println();
		
		m1.displayMatrix();
		
		System.out.println();
		System.out.println("Enter data of second matrix : ");
		System.out.print("Enter the number of rows : ");
		s=br.readLine();
		r=Integer.parseInt(s);
		System.out.print("Enter the number of columns : ");
		s=br.readLine();
		c=Integer.parseInt(s);
			
		Matrices m2=new Matrices(r,c);
		System.out.println();
		m2.addData();
		System.out.println();
		m2.displayMatrix();
		
		int ans=m1.equalMatrix(m2);
		if(ans==0)
		{
			System.out.println();
			System.out.println("Matrices are not equal");
		}
		else if(ans==1)
		{
			System.out.println();
			System.out.println("Matrices are equal");
		}
	}
}

/*
Output : 

Enter data of first matrix :
Enter the number of rows : 2
Enter the number of columns : 2

Enter data of matrix :
Enter value at index (1,1) : 1
Enter value at index (1,2) : 2
Enter value at index (2,1) : 3
Enter value at index (2,2) : 4

Data in matrix :
1       2
3       4

Enter data of second matrix :
Enter the number of rows : 2
Enter the number of columns : 2

Enter data of matrix :
Enter value at index (1,1) : 1
Enter value at index (1,2) : 2
Enter value at index (2,1) : 3
Enter value at index (2,2) : 4

Data in matrix :
1       2
3       4

Matrices are equal

*/