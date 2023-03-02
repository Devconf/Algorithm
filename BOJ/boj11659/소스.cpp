#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
int sum[100001];

void solution()
{
	for(int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << sum[b] - sum[a - 1]<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(sum, 0, sizeof(sum));

	cin >> n >> m;

	solution();
}