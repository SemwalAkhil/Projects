import numpy as np
grid=[
]
print("INSERT THE DIGITS WITHOUT SPACE( ) OR COMMA(,)")
print("INSERT EMPTY SPACES AS COMMA")
for i in range(0,9):
	row=input("ENTER DIGITS: ")
	lst=[]
	for i in row:
		lst.append(int(i))
	grid.append(lst)

mat=np.matrix(grid)
print(mat)
def poss(row,col,val):
	global grid
	for cols in range(0,9):
		if val==grid[row][cols]:
			return False
	for rows in range(0,9):
		if val==grid[rows][col]:
			return False
	col0=(col//3)*3
	row0=(row//3)*3
	for rows in range(0,3):
		for cols in range(0,3):
			if val==grid[row0+rows][col0+cols]:
				return False		
	return True
def solve():
	global grid
	for row in range(0,9):
			for col in range(0,9):
				if grid[row][col]==0:
					for val in range(1,10):
						if poss(row,col,val):
							grid[row][col]=val
							solve()
							grid[row][col]=0				
					return 
	print("ALL POSSIBLE SOLUTIONS")
	print(np.matrix(grid))
solve()