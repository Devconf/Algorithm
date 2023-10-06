#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int map[1002][1002];
int minLengh[1002][1002];
bool visit[1002][1002];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

queue<pair<int, int>> q;

void bfs()
{
	while(!q.empty())
	{
		pair<int, int> front = q.front();
		int x = front.first;
		int y = front.second;
		q.pop();


		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(map[nx][ny] != -1 && map[nx][ny] == 1 && visit[nx][ny] == false)
			{
				visit[nx][ny] = true;
				minLengh[nx][ny] = minLengh[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	memset(map, -1, sizeof(map));
	memset(minLengh, -1, sizeof(minLengh));
	memset(visit, false, sizeof(visit));
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int num;
			cin >> num;

			if(num == 2)
			{
				minLengh[i][j] = 0;
				visit[i][j] = true;
				q.push({ i,j });
			}
			if(num == 0)
			{
				minLengh[i][j] = 0;
			}
			map[i][j] = num;
		}
	}

	bfs();

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << minLengh[i][j] << " ";
		}
		cout << "\n";
	}

}