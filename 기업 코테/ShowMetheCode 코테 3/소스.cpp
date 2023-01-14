#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n, m, c;
int w[1002][1002];
vector<int> a, b;
int cnt = 0;
int sum = 0;

void solution()
{
	if(a.size() > b.size())
	{
		int nextStart = 0;
		for(int i = 1; i < b.size(); i++)
		{
			int maxNum = 0;
			int maxIdx = 0;
			for(int j = 1 + nextStart; j < a.size(); j++)
			{
				if(maxNum < w[b[i]][a[j]])
				{
					maxNum = w[b[i]][a[j]];
					maxIdx = j;
				}
			}
			nextStart = maxIdx;
			sum += maxNum;
		}
	}
	else
	{
		int nextStart = 0;
		for(int i = 1; i < a.size(); i++)
		{
			int maxNum = 0;
			int maxIdx = 0;
			for(int j = 1 + nextStart; j < b.size(); j++)
			{
				if(maxNum < w[a[i]][b[j]])
				{
					maxNum = w[a[i]][b[j]];
					maxIdx = j;
				}
			}
			nextStart = maxIdx;
			sum += maxNum;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(w, -1, sizeof(w));

	cin >> n >> m >> c;

	for(int i = 1; i <= min(n,m); i++)
	{
		for(int j = 1; j <= c; j++)
		{
			int weight;
			cin >> weight;
			w[i][j] = weight;
		}
	}

	a.push_back(0);
	b.push_back(0);

	for(int i = 0; i < n; i++)
	{
		int character;
		cin >> character;
		a.push_back(character);
	}

	for(int i = 0; i < m; i++)
	{
		int character;
		cin >> character;
		b.push_back(character);
	}

	solution();

	cout << sum;

}