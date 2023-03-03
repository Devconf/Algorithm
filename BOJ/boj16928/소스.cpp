#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;

void solution()
{
	vector<int> v(101,0);
	vector<bool> visited(101,false);
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}

	q.push({ 1,0 });

	while(!q.empty())
	{
		pair<int, int> f = q.front();
		int curr = f.first;
		int cnt = f.second;
		q.pop();

		

		if(curr == 100)
		{
			cout << cnt;
			break;
		}


		for(int i = 1; i <= 6; i++)
		{
			int next = curr + i;

			if(next > 100 || visited[next])
			{
				continue;
			}

			if(v[next] != 0)
			{
				visited[v[next]] = true;
				q.push({ v[next],cnt + 1 });
			}
			else
			{
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solution();
}