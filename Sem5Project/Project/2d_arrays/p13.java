//13. Program to determine whether a given matrix is a sparse matrix
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
	int checkSparse()
	{
		int z=0,n=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(mat[i][j]==0)
				{
					z++;
				}
				else
				{
					n++;
				}
			}
		}
		if(n>=z)
		{
			return 0;
		}
		return 1;
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
		
		System.out.println("Enter data of matrix : ");
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
		
		int ans=m1.checkSparse();
		if(ans==1)
		{
			System.out.println("Matrix is a sparse matrix");
		}
		else
		{
			System.out.println("Matrix is not a sparse matrix");
		}
	}
}

/*
Output : 

Enter data of matrix :
Enter the number of rows : 3
Enter the number of columns : 3

Enter data of matrix :
Enter value at index (1,1) : 0
Enter value at index (1,2) : 0
Enter value at index (1,3) : 1
Enter value at index (2,1) : 0
Enter value at index (2,2) : 0
Enter value at index (2,3) : 0
Enter value at index (3,1) : 1
Enter value at index (3,2) : 0
Enter value at index (3,3) : 0

Data in matrix :
0       0       1
0       0       0
1       0       0

Matrix is a sparse matrix

*/