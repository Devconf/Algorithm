#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

char map[1002][1002];
int dist[1002][1002][2];
// dist[1002][1002][0] 벽을 부수지 않고 온 거리;
// dist[1002][1002][1] 벽을 부수고 온 거리;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;

int bfs()
{
	for(int i = 0; i <= n+1; i++)
	{ // dist배열 모두 -1로 초기화
		for(int j = 0; j <= m+1; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	}
	dist[1][1][0] = dist[1][1][1] = 1;
	queue<tuple<int, int, int> > q;
	q.push({ 1,1,0 });
	while(!q.empty())
	{
		int x, y, broken;
		tie(x, y, broken) = q.front();  // q.front를 tie에 각각 저장
		if(x == n && y == m)// 우측 하단에 도착했을 때
		{
			return dist[x][y][broken];
		}

		q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] == '0' && dist[nx][ny][broken] == -1)
			{
				dist[nx][ny][broken] = dist[x][y][broken] + 1;
				q.push({ nx,ny,broken });
			}

			if(!broken && nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] == '1' && dist[nx][ny][broken] == -1)
			{
				dist[nx][ny][1] = dist[x][y][broken] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(map, ' ', sizeof(map));

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for(int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1];
		}
	}

	cout << bfs();
}



//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//char map[1002][1002];
//bool visited[1002][1002];
//int path[1002][1002];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int n, m;
//
//bool isBreakable = true;
//queue<pair<int, int>> q;
//
//void bfs()
//{
//	while(!q.empty())
//	{
//		bool isolated = true;
//		pair<int, int> f = q.front();
//		int x = f.first;
//		int y = f.second;
//		visited[x][y] = true;
//
//		q.pop();
//
//		for(int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if(nx > 0 && nx <= n && ny > 0 && ny <= m && visited[nx][ny] == false && map[nx][ny] == '0')
//			{
//				q.push({ nx,ny });
//				path[nx][ny] = path[x][y] + 1;
//				isolated = false;
//			}
//		}
//
//		if(isolated)
//		{
//			if(isBreakable)
//			{
//				isBreakable = false;
//				for(int i = 0; i < 4; i++)
//				{
//					int nx = x + dx[i];
//					int ny = y + dy[i];
//
//					if(nx > 0 && nx <= n && ny > 0 && ny <= m && visited[nx][ny] == false)
//					{
//						q.push({ nx,ny });
//						path[nx][ny] = path[x][y] + 1;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	memset(map, ' ', sizeof(map));
//	memset(visited, false, sizeof(visited));
//	memset(path, 0, sizeof(map));
//
//	cin >> n >> m;
//
//	for(int i = 1; i <= n; i++)
//	{
//		string s;
//		cin >> s;
//
//		for(int j = 1; j <= m; j++)
//		{
//			map[i][j] = s[j - 1];
//		}
//	}
//
//	if(map[1][1] == '1')
//	{
//		isBreakable = false;
//	}
//	q.push({ 1,1 });
//	bfs();
//
//	if(visited[n][m])
//	{
//		cout << path[n][m] + 1;
//	}
//	else
//	{
//		cout << -1;
//	}
//}