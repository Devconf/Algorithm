#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int v[101] = { 0, };
int w[101] = { 0, };
int dp[101][100001];
int n, k;

void solution()
{
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	//√ ±‚»≠
	for(int r = 0; r <= n; r++)
	{
		dp[r][0] = 0;
	}
	for(int c = 0; c <= k; c++)
	{
		dp[0][c] = 0;
	}

	for(int limit = 1; limit <= k; limit++)
	{
		for(int row = 1; row <= n; row++)
		{
			if(w[row] > limit)
			{
				dp[row][limit] = dp[row - 1][limit];
			}
			else
			{
				dp[row][limit] = max(dp[row - 1][limit - w[row]] + v[row], dp[row - 1][limit]);
			}
		}
	}

	cout << dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, 0, sizeof(dp));

	cin >> n >> k;
	solution();
}