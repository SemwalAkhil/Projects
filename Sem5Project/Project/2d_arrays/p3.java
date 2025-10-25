//3. Program to Multiply Two Matrices
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
	void multiplyMatrix(Matrices m)
	{
		int t;
		int mul[][]=new int[r][m.c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<m.c;j++)
			{
				t=0;
				for(int k=0;k<c;k++)
				{
					t+=this.mat[i][k]*m.mat[k][j];
				}
				mul[i][j]=t;
			}
		}
		
		System.out.println("Data after multiplication :");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<m.c;j++)
			{
				System.out.print(mul[i][j]+"	");
			}
			System.out.println();
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
		
		if(m1.c==m2.r)
		{
			System.out.println();
			System.out.println("Multipling matrix 1 and matrix 2 : ");
			m1.multiplyMatrix(m2);
		}
		else
		{
			System.out.println();
			System.out.println("Multiplication of matrices not possible");
		}
	}
}

/*
Output : 

Enter data of first matrix :
Enter the number of rows : 2
Enter the number of columns : 3

Enter data of matrix :
Enter value at index (1,1) : 4
Enter value at index (1,2) : 5
Enter value at index (1,3) : 7
Enter value at index (2,1) : 2
Enter value at index (2,2) : 1
Enter value at index (2,3) : 0

Data in matrix :
4       5       7
2       1       0

Enter data of second matrix :
Enter the number of rows : 3
Enter the number of columns : 2

Enter data of matrix :
Enter value at index (1,1) : 2
Enter value at index (1,2) : 3
Enter value at index (2,1) : 8
Enter value at index (2,2) : 9
Enter value at index (3,1) : 1
Enter value at index (3,2) : 1

Data in matrix :
2       3
8       9
1       1

Multipling matrix 1 and matrix 2 :
Data after multiplication :
55      64
12      15

*/