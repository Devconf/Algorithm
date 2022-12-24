#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int map[12][12];
int dist[12][12];
int bread[12][12];
bool visit[12][12];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(int n, int m, int r, int c)
{
	int result = 0;
	queue<pair<int, int>> q;
	q.push({ 1,1 });

	while(!q.empty())
	{
		pair<int, int> front = q.front();
		int x = front.first;
		int y = front.second;
		q.pop();

		if(visit[x][y] == false)
		{
			visit[x][y] = true;

			for(int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny] == 0 || visit[nx][ny] == true)
				{
					continue;
				}
				dist[nx][ny] = dist[x][y] + 1;
				if(bread[nx][ny] != 0)
				{
					bread[nx][ny] = max(bread[nx][ny],bread[x][y] + abs(r - nx) + abs(c - ny));
				}
				else
				{
					bread[nx][ny] = bread[x][y] + abs(r - nx) + abs(c - ny);
				}
				q.push({ nx,ny });
			}
		}
	}

	for(int j = 1; j <= n; j++)
	{

		for(int l = 1; l <= m; l++)
		{
			cout << dist[j][l] << " ";
		}
		cout << "\n";
	}

	for(int j = 1; j <= n; j++)
	{

		for(int l = 1; l <= m; l++)
		{
			cout<< bread[j][l]<<" ";
		}
		cout << "\n";
	}
}

int main()
{
	int  t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int total = 0;
		int n, m, r,c;
		cin >> n >> m >> r >> c;

		memset(map, -1, 12 * 12 * sizeof(int)); 
		memset(dist, 0, 12 * 12 * sizeof(int));
		memset(bread, 0, 12 * 12 * sizeof(int));
		memset(visit, false, 12 * 12 * sizeof(bool));

		for(int j = 1; j <= n; j++)
		{
			
			for(int l = 1; l <= m; l++)
			{
				int num;
				cin >> num;
				map[j][l] = num;
				if(num == 1)
				{
					total += abs(r - j) + abs(c - l);
				}
			}
		}


		bfs(n, m, r, c);

		cout << "#" << i << " " <<dist[n][m] << " " << total - (abs(r - 1) + abs(c - 1)) - bread[n][m] << "\n";
	}
}
