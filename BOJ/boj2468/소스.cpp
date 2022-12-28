#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int map[102][102];
bool visit[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y, int height)
{
	if(visit[x][y])
	{
		return;
	}
	visit[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>0 && nx<=n && ny>0 && ny<=n && visit[nx][ny] == false && map[nx][ny] > height)
		{
			dfs(nx, ny, height);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(map, -1, sizeof(map));
	
	int maxCnt = 0;
	
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for(int h = 0; h <= 100; h++)
	{
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!visit[i][j] && map[i][j] > h)
				{
					dfs(i,j,h);
					cnt++;
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
	}
	cout << maxCnt;
}