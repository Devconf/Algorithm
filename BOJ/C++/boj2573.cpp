#include<iostream>
#include<queue>
#include<string>
using namespace std;

pair<int, int> arr[302][302];
bool visit[302][302] = { false, };
queue<pair<int, int>> bfs;//x,y,주변 바다수
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int n, m;

void UpdateLand()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(arr[i][j].first != 0)
			{
				if(arr[i][j].first > arr[i][j].second)
				{
					arr[i][j].first = arr[i][j].first - arr[i][j].second;
					bfs.push({ i,j });
					visit[i][j] = false;
				}
				else
				{
					arr[i][j] = { 0, 0 };
				}
			}
		}
	}
}

void UpdateWater()
{
	while(!bfs.empty())
	{
		int cnt = 0;
		auto q = bfs.front();
		bfs.pop();
		auto x = q.first;
		auto y = q.second;
		for(int i = 0; i < 4; i++)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];
			if(arr[nx][ny].first == 0)
			{
				cnt++;
			}
		}
		arr[x][y].second = cnt;
	}
}

void DFS(int x,int y)
{
	visit[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		auto nx = x + dx[i];
		auto ny = y + dy[i];
		if((nx >= 1 && nx <= n) && (ny >= 1 && ny <= m) && arr[nx][ny].first != 0 && visit[nx][ny] == false)
		{
			DFS(nx, ny);
		}
	}
	return;
}


int Result()
{
	UpdateWater();
	int landCount = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(arr[i][j].first != 0 && visit[i][j] == false)
			{
				landCount++;
				DFS(i, j);
			}
		}
	}
	return landCount;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int val = 0;
			cin >> val;
			arr[i][j] = { val,0 };
			if(val != 0)
			{
				bfs.push({ i,j });
			}
		}
	}
	int result = 0;
	int year = 0;
	while(result = Result() <= 1)
	{
		year++;
		UpdateLand();
		if(bfs.empty())
		{
			year = 0;
			break;
		}
	}
	cout << year;
}
