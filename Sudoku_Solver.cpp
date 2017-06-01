#include <bits/stdc++.h>
using namespace std;
#define in insert
#define mk make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bitcnt(x) __builtin_popcount(x)
typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
const ll INF=(1<<28);
const ll MOD=(1e9+7);
int arr[11][11]={0};


bool check(int row, int column, int num)
{
	bool flag1=true;
	for(int j=0;j<9;j++)
	{
		if(arr[j][column]==num)	{flag1=false;}	//checking the presence of that number in a column
	}
	bool flag2=true;
	for(int j=0;j<9;j++)
	{
		if(arr[row][j]==num){	flag2=false;	}//checking it in same row
	}
	bool flag3=true;
	int rval=(row-(row%3));
	int cval=(column-(column%3));
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<3;k++) 
		{
			if(arr[j+rval][k+cval]==num)	{flag3=false;}		//checking in 3*3 box
		}
	}
	if(flag1 && (flag2 && flag3))	{ return true;}
	else return false;
}
bool Search_blank( int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (arr[row][col] == 0)
				return true;
	return false;
}
bool Sudoku_Solver()
{
    
	int row,col;
	if (!Search_blank(row, col))
		return true;

    
	for(int i=1;i<=9;i++)
	{
		if(check(row,col,i))
		{
			arr[row][col]=i;		//solve recursively
			if(Sudoku_Solver())	
				return true;
		arr[row][col]=0;
		}
	}
	return false;	// for backtracking
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Take the sudoku elements
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			int temp;
			cin>>temp;
			arr[i][j]=temp;
		}
	}
	int it1,it2;
	if(Sudoku_Solver()){
		for(it1=0;it1<9;it1++)
	{
		for(it2=0;it2<9;it2++)		//Printing the solved sudoku 
		{
			cout<<arr[it1][it2]<<"  ";
		}
		cout<<'\n';
	}	
	}
	else cout<<"No Solution For This Sudoku"<<'\n';
return 0;
}
