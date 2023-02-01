#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 0, sizeof(arr));

	string a, b;

	cin >> a >> b;

	for(int i = 1; i <= a.size(); i++)
	{
		for(int j = 1; j <= b.size(); j++)
		{
			if(a[i - 1] == b[j- 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	cout << arr[a.size()][b.size()];
}