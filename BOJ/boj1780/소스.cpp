#include<iostream>
#include<cstring>
using namespace std;

int n;
int arr[2200][2200];
int blueCnt = 0, whiteCnt = 0, blackCnt = 0;

void solution(int x, int y, int size)
{
	bool blue = false;
	bool white = false;
	bool black = false;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(arr[x + i][y + j] == 1)
			{
				blue = true;
			}
			if(arr[x + i][y + j] == 0)
			{
				white = true;
			}
			if(arr[x + i][y + j] == -1)
			{
				black = true;
			}
		}
	}

	if(blue && white || blue && black || black && white)
	{
		int newSize = size / 3;
		if(newSize == 0)
		{
			return;
		}
		solution(x, y, newSize);
		solution(x, y + newSize, newSize);
		solution(x, y + 2*newSize, newSize);
		solution(x + newSize, y, newSize);
		solution(x + 2*newSize, y, newSize);
		solution(x + newSize, y + newSize, newSize);
		solution(x + newSize, y + 2*newSize, newSize);
		solution(x + 2*newSize, y + newSize, newSize);
		solution(x + 2*newSize, y + 2*newSize, newSize);
	}
	else if(blue)
	{
		blueCnt++;
	}
	else if(white)
	{
		whiteCnt++;
	}
	else if(black)
	{
		blackCnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 2, sizeof(arr));

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	solution(1, 1, n);

	cout << blackCnt << "\n" << whiteCnt << "\n" << blueCnt;

}