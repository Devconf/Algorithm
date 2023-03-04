#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int num;
int arr[50001];

void solution()
{
	for(int i = 1; i*i <= 50000; i++)
	{
		arr[i*i] = 1;
	}

	for(int i = 1; i <= 50000; i++)
	{
		int minCnt = 4;
		int sqrt_i = sqrt(i);
		if(arr[i] == 0)
		{
			for(int j = sqrt_i; j > 0; j--)
			{
				minCnt = min(minCnt, (arr[i - j*j] + arr[j*j]));
				arr[i] = minCnt;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 0, sizeof(arr));

	cin >> num;

	solution();

	cout << arr[num];
}