#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visited[1001][1001];
int map[1001][1001];
queue<pair<int, int>> q;
int cnt = 0;

void dfs(int x, int y)
{
	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0)
		{
			nx = n + nx;
		}
		if(nx == n)
		{
			nx = nx - n;
		}
		if(ny < 0)
		{
			ny = m + ny;
		}
		if(ny == m)
		{
			ny = ny - m;
		}

		if(visited[nx][ny] == false && map[nx][ny] != 1)
		{
			dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, -1, sizeof(map));

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num;
			if(num == 0)
			{
				q.push({ i,j });
			}
		}
	}

	while(!q.empty())
	{
		int x, y;
		pair<int, int> p = q.front();
		x = p.first;
		y = p.second;
		q.pop();

		if(visited[x][y] == false)
		{
			cnt++;
			dfs(x,y);
		}
	}
	
	cout << cnt;

}