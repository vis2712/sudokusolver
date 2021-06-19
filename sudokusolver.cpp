#include <iostream>
using namespace std;
#define N 9

bool issafe(int** a,int row,int col,int val)
{

	if(row>=0 && row<=2)
	{
		if(col>=0 && col<=2)
		{
			for(int i=0; i<=2; i++)
			{
				for(int j=0; j<=2; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=3 && col<=5)
		{
			for(int i=0; i<=2; i++)
			{
				for(int j=3; j<=5; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=6 && col<=8)
		{
			for(int i=0; i<=2; i++)
			{
				for(int j=6; j<=8; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
	}

	if(row>=3 && row<=5)
	{
		if(col>=0 && col<=2)
		{
			for(int i=3; i<=5; i++)
			{
				for(int j=0; j<=2; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=3 && col<=5)
		{
			for(int i=3; i<=5; i++)
			{
				for(int j=3; j<=5; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=6 && col<=8)
		{
			for(int i=3; i<=5; i++)
			{
				for(int j=6; j<=8; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
	}

	if(row>=6 && row<=8)
	{
		if(col>=0 && col<=2)
		{
			for(int i=6; i<=8; i++)
			{
				for(int j=0; j<=2; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=3 && col<=5)
		{
			for(int i=6; i<=8; i++)
			{
				for(int j=3; j<=5; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
		if(col>=6 && col<=8)
		{
			for(int i=6; i<=8; i++)
			{
				for(int j=6; j<=8; j++)
				{
					if(a[i][j] == val)
					{
						return false;
					}
				}
			}
		}
	}

	for(int i=0; i<N; i++)
	{
		if(a[row][i] == val)
			return false;
	}
	for(int i=0; i<N; i++)
	{
		if(a[i][col] == val)
			return false;
	}

	return true;
}


bool sudokusolver(int** a,int row,int col)
{
	if(row>=N)
	{
		return true;
	}

	if(col>=N)
	{
		if(sudokusolver(a,row+1,0))
		{
			return true;
		}
	}

	if(a[row][col]!=0)
	{
		if(sudokusolver(a,row,col+1))
		{
			return true;
		}
	}

	if(a[row][col] == 0)
	{
		for(int i=1; i<=9; i++)
		{
			if(issafe(a,row,col,i))
			{
				a[row][col] = i;
				if(sudokusolver(a,row,col+1))
				{
					return true;
				}
				a[row][col] = 0;
			}
		}
	}
	return false;
}

int main()
{
	int** a = new int*[9];
	for(int i=0; i<9; i++)
	{
		a[i]=new int[9];
		for(int j=0; j<9; j++)
		{
			cin>>a[i][j];
		}	
	}
	cout<<endl<<endl;

	//cout<<issafe(a,0,0,1);


	cout<<sudokusolver(a,0,0)<<endl<<endl;

	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}

return 0;
}
/*0 8 0 7 0 1 0 3 0
4 0 9 0 0 0 0 0 0
0 5 0 0 6 0 4 1 8
7 0 0 0 0 9 0 0 0
8 0 0 6 1 0 5 0 0
0 3 5 0 0 0 0 2 9
0 6 0 4 0 7 0 9 0
1 0 0 0 0 8 0 0 4
0 2 0 0 5 0 0 7 0*/